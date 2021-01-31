#include "howl.h"
#include "ui_howl.h"

Howl::Howl(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Howl)
{
    ui->setupUi(this);
    m_player = new QMediaPlayer();

    m_file = new QMenu("Зырь сюда, да?");
    m_file_open = new QAction("Add to playlist...");

    m_file->addAction(m_file_open);
    ui->menubar->addMenu(m_file);

    ui->l_song_name->setText("Орать нечего");
    ui->s_progress->setValue(0);
    ui->vs_volume->setValue(50);

    connect (m_file_open, &QAction::triggered, this, &Howl::openFile);
    connect (ui->b_play, &QPushButton::clicked, this, &Howl::play);
    connect (ui->vs_volume, &QSlider::valueChanged, m_player, &QMediaPlayer::setVolume);
    connect (m_player, &QMediaPlayer::positionChanged, this, &Howl::calculatePosition);
    connect (ui->b_ff, &QPushButton::clicked, this, &Howl::fastForward);
    connect (ui->s_progress, &QSlider::sliderReleased, this, &Howl::progerssSliderReleased);
    connect (ui->b_playlist_play, &QPushButton::clicked, this, &Howl::playlistPlayPressed);
    connect (ui->b_playlist_remove, &QPushButton::clicked, this, &Howl::playlistRemovePressed);
    connect (ui->b_save_playlist, &QPushButton::clicked, this, &Howl::savePlaylistPressed);
    connect (ui->b_load_playlist, &QPushButton::clicked, this, &Howl::loadPlaylistPressed);
}

Howl::~Howl()
{
    delete ui;
}

void Howl::openFile()
{
    QString path = QFileDialog::getOpenFileName(this, "Что именно мы будем орать?", QDir::homePath(), "MP3 *.mp3");
    playlist.append(path);
    playListChanged();

    if (playlist.size() < 2) {
        m_player->setMedia(QUrl::fromLocalFile(path));
        ui->l_song_name->setText(path.remove(0, path.lastIndexOf("/") + 1));
    }
}

void Howl::play()
{
    m_player->play();
    ui->b_play->setText("||");
    disconnect (ui->b_play, &QPushButton::clicked, this, &Howl::play);
    connect (ui->b_play, &QPushButton::clicked, this, &Howl::pause);
}

void Howl::pause()
{
    m_player->pause();
    ui->b_play->setText(">");
    disconnect (ui->b_play, &QPushButton::clicked, this, &Howl::pause);
    connect (ui->b_play, &QPushButton::clicked, this, &Howl::play);
}

void Howl::calculatePosition(qint64 position)
{
    if (m_player->duration() == 0)
        return;

    int progress = position / (m_player->duration() / 100);
    ui->s_progress->setValue(progress);
    qDebug() << "Current: " << position << " :::: Full: " << m_player->duration() << " :::: progress: " << progress;
}

void Howl::fastForward()
{
    m_player->setPosition(m_player->position() + 1000);
}

void Howl::progerssSliderReleased()
{
    double multiplier = (double) ui->s_progress->value() / 100;
    qDebug() << "multiplier:" << multiplier;
    m_player->setPosition(m_player->duration() * multiplier);
}

void Howl::playListChanged()
{
    ui->l_playlist->clear();
    for (QString song : playlist) {
        ui->l_playlist->addItem(song.remove(0, song.lastIndexOf("/") + 1));
    }
}

void Howl::playlistPlayPressed()
{
    int index = ui->l_playlist->currentIndex().row();
    qDebug() << playlist[index];
    m_player->setMedia(QUrl::fromLocalFile( playlist[index] ));
    ui->l_song_name->setText(playlist[index].remove(0, playlist[index].lastIndexOf("/") + 1));
}

void Howl::playlistRemovePressed()
{
    int index = ui->l_playlist->currentIndex().row();
    qDebug() << playlist[index];
    m_player->stop();
    ui->s_progress->setValue(0);
    ui->l_song_name->setText("Орать нечего");
    playlist.remove(index);
    playListChanged();
}

void Howl::savePlaylistPressed()
{
    QString file;
    for (QString path : playlist) {
        file.append(path + "\n");
    }
    file.chop(1);
    qDebug() << file;

    QString path = QFileDialog::getSaveFileName(this, "Сюда подошел",
                                              "/",
                                              "Playlist files (*.playlist);;Text files (*.txt);;All files (*)");
    if (path.isEmpty()) return;

    QFile fileToSave(path);
    if (fileToSave.open(QIODevice::WriteOnly)) {

        QTextStream to(&fileToSave);
        to << file;

        fileToSave.close();
    } else {
        QMessageBox::warning(this, "Wow, we can't open the file!", fileToSave.errorString());
    }
}

void Howl::loadPlaylistPressed()
{
    QString path = QFileDialog::getOpenFileName(this, "Откуда грузить",
                                                "/",
                                                "Playlist files (*.playlist);;Text files (*.txt);;All files (*)");
    if (path.isEmpty())
        return;

    QFile fileToLoad(path);
    if (fileToLoad.open(QIODevice::ReadOnly)) {

        QTextStream from(&fileToLoad);

//        while (from.atEnd()) playlist.append(from.readLine()); // line-by-line read dont work :c
        playlist.append( from.readAll().split("\n").toVector() );

        fileToLoad.close();
    } else {
        QMessageBox::warning(this, "Wow, we can't open the file!", fileToLoad.errorString());
    }
    playListChanged();

//    for (QString s : playlist) {
//        qDebug() << "s:" << s;
//    }
}

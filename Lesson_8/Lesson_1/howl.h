#ifndef HOWL_H
#define HOWL_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Howl; }
QT_END_NAMESPACE

class Howl : public QMainWindow
{
    Q_OBJECT

public:
    Howl(QWidget *parent = nullptr);
    ~Howl();

private slots:
    void openFile();
    void play();
    void pause();
    void calculatePosition(qint64 position);
    void fastForward();
    void progerssSliderReleased();
    void playListChanged();
    void playlistPlayPressed();
    void playlistRemovePressed();
    void savePlaylistPressed();
    void loadPlaylistPressed();

private:
    Ui::Howl *ui;
    QMediaPlayer *m_player;
    QVector<QString> playlist;

    QMenu *m_file;
    QAction *m_file_open;
};
#endif // HOWL_H


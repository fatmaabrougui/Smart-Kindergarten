#ifndef PLAYER_H
#define PLAYER_H

#include <playlist.h>
#include <QMediaPlayer>
#include <QObject>

class Player : public QObject {
  Q_OBJECT

public:
  static Player * GetInstance();

  void SetPlaylist(Playlist * playlist);

  void Play();
  void Stop();
  void Pause();
  void NextSong();
  void PreviousSong();
  void SetVolume(int volume);

  qint64 GetCurrentSongDuration();
  void SetPosition(qint64 second);
  void SetSong(int playlistIndex);

public slots:
  void RecievePositionChanged(qint64 position);
  void CurrentPlaylistIndexChanged(int currentPlaylistIndex);

signals:
  void PositionChanged(qint64);
  void CurrentSongChanged(int);

private:
  Player();

  static Player * playerInstance_;

  QMediaPlayer * player_;
  Playlist * playlist_;
};

#endif // PLAYER_H

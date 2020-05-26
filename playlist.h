#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QMediaPlaylist>
#include <QObject>

class Playlist : public QObject {
  Q_OBJECT

public:
  Playlist();

  QMediaPlaylist * GetPlaylist();

  void AddSong(QString filePath);
  void RemoveSong(int position);
  void NextSong();
  void PreviousSong();
  void SetCurrentIndex(int index);
  int GetCurrentIndex();

  void Save(QUrl location);
  void Load(QUrl location);

  int MediaCount();

public slots:
  void CurrentIndexChangedSlot();
  void MediaChangedSlot();

signals:
  void CurrentIndexChanged(int);
  void MediaChanged();

private:
  QMediaPlaylist * playlist_;
};

#endif // PLAYLIST_H

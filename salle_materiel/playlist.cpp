#include "playlist.h"

Playlist::Playlist() {
  playlist_ = new QMediaPlaylist;

  connect(playlist_, SIGNAL(currentIndexChanged(int)), this, SLOT(CurrentIndexChangedSlot()));
  connect(playlist_, SIGNAL(mediaInserted(int, int)), this, SLOT(MediaChangedSlot()));
  connect(playlist_, SIGNAL(mediaRemoved(int, int)), this, SLOT(MediaChangedSlot()));
  connect(playlist_, SIGNAL(mediaRemoved(int, int)), this, SLOT(CurrentIndexChangedSlot()));
}

QMediaPlaylist * Playlist::GetPlaylist() {
  return playlist_;
}

void Playlist::AddSong(QString filePath) {
    playlist_->addMedia(QUrl(filePath));
}

void Playlist::RemoveSong(int position) {
  playlist_->removeMedia(position);
}

void Playlist::NextSong() {
  playlist_->next();
}

void Playlist::PreviousSong() {
  playlist_->previous();
}

void Playlist::SetCurrentIndex(int index) {
  playlist_->setCurrentIndex(index);
}

int Playlist::GetCurrentIndex() {
  return playlist_->currentIndex();
}

void Playlist::Save(QUrl location) {
  playlist_->save(location, "m3u");
}

void Playlist::Load(QUrl location) {
  playlist_->load(location);
}

int Playlist::MediaCount() {
  return playlist_->mediaCount();
}

void Playlist::CurrentIndexChangedSlot() {
  emit CurrentIndexChanged(GetCurrentIndex());
}

void Playlist::MediaChangedSlot() {
  emit MediaChanged();
}

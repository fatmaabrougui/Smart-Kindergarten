#include "player.h"

Player * Player::playerInstance_ = nullptr;

Player::Player() {
  player_ = new QMediaPlayer();

  connect(player_, SIGNAL(positionChanged(qint64)), this, SLOT(RecievePositionChanged(qint64)));
}

Player * Player::GetInstance() {
  if (!playerInstance_) {
    playerInstance_ = new Player();
  }

  return playerInstance_;
}

void Player::SetPlaylist(Playlist * playlist) {
  playlist_ = playlist;

  player_->setPlaylist(playlist_->GetPlaylist());

  connect(playlist_, SIGNAL(CurrentIndexChanged(int)), this, SLOT(CurrentPlaylistIndexChanged(int)));
}

void Player::Play() {
  player_->play();
}

void Player::Stop() {
  player_->stop();
}

void Player::Pause() {
  player_->pause();
}

void Player::NextSong() {
  playlist_->NextSong();
}

void Player::PreviousSong() {
  playlist_->PreviousSong();
}

void Player::SetVolume(int volume) {
  player_->setVolume(volume);
}

qint64 Player::GetCurrentSongDuration() {
  return player_->duration();
}

void Player::SetPosition(qint64 second) {
  player_->setPosition(second);
}

void Player::SetSong(int playlistIndex) {
  playlist_->SetCurrentIndex(playlistIndex);
}

void Player::RecievePositionChanged(qint64 position) {
  emit PositionChanged(position);
}

void Player::CurrentPlaylistIndexChanged(int currentPlaylistIndex) {
  emit CurrentSongChanged(currentPlaylistIndex);
}

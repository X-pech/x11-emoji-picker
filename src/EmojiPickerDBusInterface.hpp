#pragma once

#include <QDBusConnection>
#include <QObject>
#include <functional>

class EmojiPickerDBusInterface : public QObject {
  Q_OBJECT;
  Q_CLASSINFO("D-Bus Interface", "xyz.gazatu.EmojiPicker");

public:
  std::function<void(const QString&, const QString&)> _show;
  std::function<void()> _hide;

  EmojiPickerDBusInterface(QObject* parent, QDBusConnection::BusType busType);
  virtual ~EmojiPickerDBusInterface();

public slots:
  void show(const QString& display, const QString& xauthority);
  void hide();
};

#pragma once

#include <QWidget>
#include <QSystemTrayIcon>

class QTabWidget;

//
// Declaration of the class TabWidget.
//

class TabWidget
	: public QWidget
{
	Q_OBJECT

		//
		// Constructions.
		//

public:
	//! Constructor.
	TabWidget(const QString &fileName, QWidget *parent = 0);

	//
	// Private interface.
	//

private:
	//! Ignores the usual closing of the application
	void closeEvent(QCloseEvent* event) override;

	//
	// Private slots.
	//

	private slots:
	//! Shows the icon of the application in the tray for a certain time
	void ShowMessageInTray();

	//! Responds to mouse clicks on the icon to disappear/appear widget in the system tray
	void TrayIconActivated(QSystemTrayIcon::ActivationReason reason);

	//
	// Private data members.
	//

private:
	QSystemTrayIcon* trayIcon_;
	QTabWidget *mainTab_;
};



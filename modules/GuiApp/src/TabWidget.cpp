#include "pch.h"

#include "TabWidget.h"
#include <ProfileTab.h>

TabWidget::TabWidget(const QString &fileName, QWidget *parent)
	: QWidget(parent)
{
	QFileInfo fileInfo(fileName);

	mainTab_ = new QTabWidget();
	mainTab_->addTab(new ProfileTab(fileInfo), tr("Profiles"));

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(mainTab_);
	setLayout(mainLayout);

	trayIcon_ = new QSystemTrayIcon(QIcon(":/images/LofoForBackup.png"), this);
	connect(
		trayIcon_,
		SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
		SLOT(TrayIconActivated(QSystemTrayIcon::ActivationReason))
	);

	QMenu* menu = new QMenu;
	QAction* exitAction = menu->addAction("Exit");
	connect(exitAction, SIGNAL(triggered(bool)), SLOT(close()));

	trayIcon_->setContextMenu(menu);
	trayIcon_->show();

	QPalette pal(Qt::cyan);
	setPalette(pal);

	setWindowTitle(tr("Backuper"));
	setMinimumHeight(600);
	setMaximumHeight(600);
	setMinimumWidth(900);
	setMaximumWidth(900);
}

void TabWidget::closeEvent(QCloseEvent* event)
{
	hide();
	event->ignore();
}

void TabWidget::TrayIconActivated(QSystemTrayIcon::ActivationReason reason) {
	switch (reason) {
	case QSystemTrayIcon::Trigger:
		setVisible(!isVisible());
		break;

	default:
		break;
	}
}

void TabWidget::ShowMessageInTray() {
	trayIcon_->showMessage("Message title", "Message text", QSystemTrayIcon::Information);
}



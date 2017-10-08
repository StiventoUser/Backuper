#pragma once

#include <QWidget>

class QFileInfo;
class QLabel;
class QPushButton;
class QStringList;
class QTimer;
class QTableWidget;
class QTableWidgetItem;

//
// Declaration of the class TabWidget.
//

class ProfileTab
	: public QWidget
{
	Q_OBJECT

		//
		// Construction and destruction.
		//

public:
	//! Constructor
	ProfileTab(const QFileInfo &fileInfo, QWidget *parent = 0);

	//
	// Private slots.
	//

	private slots:
	//! Checks the date and time of profile for backup in certain time
	void CheckingDateTimeProfile();

	//! Shows QWizardPages with different settings for creating new profile
	void ClickedAddNew();

	//! Creates dialog window
	void ClickedAddExisted();

	//! Deletes selected profile
	void ClickedDelete();

	//! Displays all profiles
	void DisplayProfiles();

	//
	// Private data members.
	//				

private:
	QPushButton *buttonAddNew_;
	QPushButton *buttonAddExisted_;
	QPushButton *buttonBackup_;
	int count_ = 0;
	QPushButton *buttonDel_;
	QPushButton *buttonEdit_;
	QStringList headerTableForListProfile_;
	QTableWidgetItem *itemFiles_;
	QLabel *labListSelectedFiles_;
	QPushButton *buttonRestore_;
	QTimer *tmrBackupProfile_;
	QTableWidget *tableListFiles_;
};

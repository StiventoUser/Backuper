#pragma once

#include <QWizard>
#include <QWizardPage>

class QCalendarWidget;
class QComboBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QListWidget;
class QRadioButton;
class QSlider;
class QSpinBox;
class QTimeEdit;

//
// Declaration of the enum Pages.
//

enum Pages {
	INTRO_PAGE,
	INFO_PROFILE_PAGE,
	FILES_PAGE,
	DATE_BACKUP_PROFILE,
	SPEC_DATE_BACKUP_PAGE,
	DATE_EVERY_WEEK_BACKUP_PAGE,
	CONCLUSION_PAGE
};

//
// Declaration of the class QWizardNewProfile.
//

class WizardNewProfile :
	public QWizard
{
	Q_OBJECT

	//
	// Construction and destruction.
	//

public:
	//!Constructor
	WizardNewProfile(QWidget *parent = 0);

	//
	// Private methods.
	//

private:
	//!Show message with warning if user try to stop creating new profile
	void reject() override;

	//
	// Private slots
	//

	private slots:
	void accept() override;
};


//
// Declaration of the class QWizardIntroPage.
//

class WizardIntroPage
	: public QWizardPage
{
	//
	// Construction and destruction.
	//

public:
	//!Constructor
	WizardIntroPage(QWidget *parent = 0);

	//
	// Private data members.
	//

private:
	QLabel *labFotIntroInfo_;
	QLabel *labForIntroPict_;
};


//
// Declaration of the class QWizardInfoProfilePage.
//

class WizardInfoProfilePage
	: public QWizardPage
{
	//
	// Construction and destruction.
	//

public:
	//!Constructor
	WizardInfoProfilePage(QWidget *parent = 0);

	//
	// Private data members.
	//

private:
	QLabel *labProfileName_;
	QLabel *labComprLvl_;
	QLabel *labViewComprLvl_;
	QLabel *labChunkSize_;
	QLabel *labPicture_;
	QLabel *labInfoPage_;
	QLineEdit *lineProfileName_;
	QSlider *sliderComprLvl_;
	QSpinBox *  sbChunkSize_;
};

//
// Declaration of the class QWizardFilesPage.
//

class WizardFilesPage
	: public QWizardPage
{
	Q_OBJECT

		Q_PROPERTY(QStringList theStringList READ theStringList)

		//
		// Construction and destruction.
		//

public:
	//!Constructor
	WizardFilesPage(QWidget *parent = 0);

	//
	// Protected methods
	//

protected:
	//!Finds out which page to show when the user clicks the Next button and checks values of page
	int nextId() const override;

	//!Returns list of added file paths
	QStringList theStringList() const;

	//
	// Private slots
	//

	private slots:
	//!Shows a list of files to add file to backup list
	void ClickedAddFile();

	//!Shows a list of files to add directory to backup list
	void ClickedAddDirectory();

	//!Shows a list of files to select the result file for backup
	void ClickedResultFile();

	//
	// Private data members.
	//

private:

	QPushButton *butResultFile_;
	QPushButton *butAddFile_;
	QPushButton *butAddDirectory_;
	int count_ = 0;
	QLabel *labInfoPage_;
	QLabel *labPicture_;
	QLabel *labResultFile_;
	QLabel *labPathResFile_;
	QLabel *labListSelectedFiles_;
	QListWidget *listFiles_;
};

//
// Declaration of the class QWizardBackupProfile.
//

class WizardDateBackupProfile
	: public QWizardPage
{
	Q_OBJECT

		Q_PROPERTY(QString theString READ theString)

		//
		// Construction and destruction.
		//

public:
	//!Constructor
	WizardDateBackupProfile(QWidget *parent = 0);

	//
	// Protected methods
	//

protected:
	//!Finds out which page to return when the user clicks the Next button and checks values of page
	int nextId() const override;

	//!Returns string with certain backup repeat
	QString theString() const;

	//
	// Private data members.
	//

private:
	QRadioButton *rbEveryDay_;
	QRadioButton *rbEveryWeek_;
	QGroupBox *grb_;
	QLabel *labInfoPage_;
	QLabel *labPicture_;
	QLabel *labTimeDate_;
	QRadioButton *rbNoDate_;
	QRadioButton *rbSpecDate_;
	QTimeEdit *time_;
};

//
// Declaration of the class QWizardDateEveryWeekBackupPage.
//

class WizardDateEveryWeekBackupPage
	: public QWizardPage
{
	Q_OBJECT

		Q_PROPERTY(QString theStringDayWeek READ theStringDayWeek)

		//
		// Construction and destruction.
		//

public:
	//! Constructor
	WizardDateEveryWeekBackupPage(QWidget *parent = 0);

	//
	// Protected methods
	//

protected:
	//! Returns day of week for backup repeat
	QString theStringDayWeek() const;

	//
	// Private data members.
	//

private:
	QComboBox *combDaysWeek_;
	QLabel *labPicture_;
	QLabel *labInfoPage_;
	QLabel *labCombDaysWeek_;
	QStringList strListDaysWeek_;
};

//
// Declaration of the class QWizardSpecDateBackupPage.
//

class WizardSpecDateBackupPage
	: public QWizardPage
{
	Q_OBJECT

		Q_PROPERTY(QString theStringDateBackup READ theStringDateBackup)

		//
		// Construction and destruction.
		//

public:
	//! Constructor
	WizardSpecDateBackupPage(QWidget *parent = 0);

	//
	// Protected methods
	//

protected:
	//! Returns conclusion page after specifying date
	int nextId() const; //delete if not used

						//! Returns date for profile backup
	QString theStringDateBackup() const;

	//
	// Private data members.
	//

private:
	QCalendarWidget *calendar_;
	QLabel *labPicture_;
	QLabel *labInfoPage_;
	QLabel *labCalendar_;
};

//
// Declaration of the class QWizardConclusionPage.
//

class WizardConclusionPage
	: public QWizardPage
{
	//
	// Construction and destruction.
	//

public:
	//! Constructor
	WizardConclusionPage(QWidget *parent = 0);

	//
	// Private data members.
	//

private:
	QLabel *labForIntroPict_;
	QLabel *labConclInfo_;
};

#pragma once

namespace BackupManager
{

//
// Declaration of the BackupProfile class.
//

class BackupProfile
{
	//
	// Public interface.
	//
public:
	//! Returns empty directory postfix.
	QString GetEmptyDirPostfix() const;

	//! Returns profile's name.
	QString GetProfileName() const;
	//! Returns profile's date for backup.
	QString GetProfileDate() const;
	//! Returns profile's time for backup.
	QString GetProfileTime() const;
	//! Returns option to date of backup profile.
	QString GetOptionBackupDate() const;
	//! Returns path to backup file.
	QString GetBackupFilePath() const;
	//! Returns paths to backuped files.
	const QStringList& GetBackupedFilesPath() const;
	//! Returns chunk size.
	quint64 GetChunkSize() const;
	//! Returns data compression level.
	qint32 GetCompressionLevel() const;

	//! Sets profile's name.
	void SetProfileName(const QString& name);
	//! Sets path to backup file/.
	void SetBackupFilePath(const QString& path);
	//! Sets paths to backupe files.
	void SetBackupedFilesPath(const QStringList& list);
	//! Adds path to backuped files list.
	void AddBackupedFilePath(const QString& path);
	//! Adds path to backuped folder.
	void AddBackupedFolderPath(const QString& path);
	//! Sets date profile for backup.
	void SetDateProfileBackup(const QString& date);
	//! Sets time profile for backup.
	void SetTimeProfileBackup(const QString& time);
	//! Sets option to date of backup profile.
	void SetOptionBackupDate(const QString& backupDateOption);
	//! Sets chunk size.
	void SetChunkSize(const quint64 chunkSIze);
	//! Sets data compression level.
	void SetCompressionLevel(const qint32 level);
	

	//! Loads profile from file.
	void LoadProfile();
	//! Saves profile to the file.
	void SaveProfile() const;


	//
	// Private data members.
	//
private:
	//! Path postfix to save empty directories.
	const QString emptyDirPostfix_ = "!*NotAFile*!";

	//! Profile's name.
	QString profileName_;
	//! Profile's date for backup.
	QString date_;
	//! Profile's time for backup.
	QString time_;
	//! Option to date of backup profile.
	QString backupDateOption_;
	//! Chunk size in MB.	
	quint64 chunkSize_ = 256;
	//! Path to backup file.
	QString backupFilePath_;
	//! Paths to backuped files.
	QStringList backupedFilesPath_;
	//! Data compression level.
	qint32 compressionLevel_ = -1; // default.
};

//
// Inline implementation.
//

inline QString BackupProfile::GetEmptyDirPostfix() const
{
	return emptyDirPostfix_;
}

inline QString BackupProfile::GetProfileName() const
{
	return profileName_;
}

inline QString BackupProfile::GetProfileDate() const
{
	return date_;
}

inline QString BackupProfile::GetProfileTime() const
{
	return time_;
}

inline QString BackupProfile::GetOptionBackupDate() const
{
	return backupDateOption_;
}

inline QString BackupProfile::GetBackupFilePath() const
{
	return backupFilePath_;
}

inline const QStringList& BackupProfile::GetBackupedFilesPath() const
{
	return backupedFilesPath_;
}

inline quint64 BackupProfile::GetChunkSize() const
{
	return chunkSize_;
}

inline qint32 BackupProfile::GetCompressionLevel() const
{
	return compressionLevel_;
}

inline void BackupProfile::SetProfileName(const QString& name)
{
	profileName_ = name;
}

inline void BackupProfile::SetBackupFilePath(const QString& path)
{
	backupFilePath_ = path;
}

inline void BackupProfile::SetBackupedFilesPath(const QStringList& list)
{
	backupedFilesPath_ = list;
}

inline void BackupProfile::AddBackupedFilePath(const QString& path)
{
	backupedFilesPath_.push_back(path);
}

inline void BackupProfile::SetDateProfileBackup(const QString& date)
{
	date_ = date;
}

inline void BackupProfile::SetTimeProfileBackup(const QString& time)
{
	time_ = time;
}

inline void BackupProfile::SetOptionBackupDate(const QString& backupDateOption)
{
	backupDateOption_ = backupDateOption;
}

inline void BackupProfile::SetChunkSize(const quint64 chunkSize)
{
	chunkSize_ = chunkSize;
}

inline void BackupProfile::SetCompressionLevel(const qint32 level)
{
	compressionLevel_ = level;
}

} // namespace BackupManager

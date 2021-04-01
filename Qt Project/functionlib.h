#ifndef FUNCTIONLIB
#define FUNCTIONLIB

#include <QString>
#include <QStringList>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QDir>
#include <QTextStream>

#define Qendl "\n"


/********************************************************************************************
 * Globale Variablen
 */


/********************************************************************************************
 * Operator überladen
 */

std::ostream& operator << (std::ostream& output, const QString& string)
{
	return output << string.toStdString();
}

std::ostream& operator << (std::ostream& output, const QStringList& list)
{
	for(int i = 0; i != list.size(); i++)
		output << list.at(i) << std::endl;

	return output;
}

QTextStream& operator << (QTextStream& output, const QStringList& list)
{
	for(int i = 0; i != list.size(); i++)
		output << list.at(i) << Qendl;

	return output;
}

std::istream& operator >> (std::istream& input, QString& string)
{
	std::string temp;
	input >> temp;
	string = QString::fromStdString(temp);
	return input;
}

std::istream& operator >> (std::istream& input, QStringList& list)
{
	std::string tempString;
	QString tempQString;

	std::getline(input, tempString);

	tempQString = QString::fromStdString(tempString);
	list = tempQString.split(" ");

	return input;
}

QTextStream& operator >> (QTextStream& input, QStringList& list)
{
	while(!input.atEnd())
	{
		QString temp = input.readLine();

		if(!temp.isEmpty())
			list << temp;
	}

	return input;
}


/********************************************************************************************
 * Funktionen
 */

QString getUsername()
{
	QString name = qgetenv("USER");
	if (name.isEmpty())
		name = qgetenv("USERNAME");

	return name;
}

void initList(QStringList &inputFileList)
{
	QDir inputDir("../CustomLVL");
	inputFileList = inputDir.entryList(QStringList("*.req"), QDir::Files);
}

void copyFile(QString fileName, QString plattform)
{
	QFile copyInfoFile("../CustomLVL/" + fileName + ".customlvl");
	QString source = "../_LVL_" + plattform + "/CustomLVL/" + fileName;
	source.replace(".req", ".lvl");

	if(copyInfoFile.open(QIODevice::ReadOnly))
	{
		QTextStream infoStream(&copyInfoFile);

		while(!infoStream.atEnd())
		{
			QString destination = infoStream.readLine();

			destination.replace("%username%", getUsername());

			QFile::remove(destination);
			QFile::copy(source, destination);
		}
	}
}

void deleteFile(QString fileName)
{
	QFile deleteInfoFile("../CustomLVL/" + fileName + ".customlvl");

	if(deleteInfoFile.open(QIODevice::ReadOnly))
	{
		QTextStream infoStream(&deleteInfoFile);

		while(!infoStream.atEnd())
		{
			QString removeFile = infoStream.readLine();
			removeFile.replace("%username%", getUsername());
			QFile::remove(removeFile);
		}
	}
}



#endif // FUNCTIONLIB

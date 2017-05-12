#pragma once
class Date
{

private:
	int month, day, year;
	unsigned long days;
public:
	struct sDatum
	{
		int month, day, year;
	};

	//These are consturctors
	Date();
	Date(int Tag, int Monat, int Jahr);
	void setDatum(int Tag, int Monat, int Jahr);
	void setDatum(Date::sDatum in);
	Date::sDatum getDatum();
	void setTag(int Tag);
	void setMonat(int Monat);
	void setJahr(int Jahr);

	

	char* toString();

	enum Wochentag
	{
		Monatag,
		Dienstag,
		Mittwoch,
		Donnerstag,
		Freitag,
		Samstag,
		Sonntag
	};
	inline const char* WochentagToString(Wochentag w) {
		switch (w)
		{
		case Date::Monatag: return "Montag";
			break;
		case Date::Dienstag: return "Dienstag";
			break;
		case Date::Mittwoch: return "Mittwoch";
			break;
		case Date::Donnerstag: return "Donnerstag";
			break;
		case Date::Freitag: return "Freitag";
			break;
		case Date::Samstag: return "Samstag";
			break;
		case Date::Sonntag: return "Sonntag";
			break;
		default: return "ERROR";
			break;
		}
	}

	enum Monat
	{
		Januar,
		Februar,
		März,
		April,
		Mai,
		Juli,
		Juni,
		August,
		September,
		Oktober,
		November,
		Dezember
	};

	Date::Wochentag getWochentag();


	//Destructor 
	~Date();
};


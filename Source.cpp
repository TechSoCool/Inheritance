#include<iostream>
#include<list>
using namespace std;

class YouTubeChannel // Base Class what the program inherit from
{
	private:
		string Name;
		string OwnerName;
		int SubscribersCount;
		list<string>PublishedVideoTitles;

	public:
		YouTubeChannel(string name, string ownerName) // constructor with parameters
		{
			Name = name;
			OwnerName = ownerName;
			SubscribersCount = 0;
		}
		void GetInfo()
		{
			cout << "Name: " << Name << endl;
			cout << "OwnerName: " << OwnerName << endl;
			cout << "SubcribersCount: " << SubscribersCount << endl;
			cout << "Videos" << endl;
			for (string videoTitle : PublishedVideoTitles) {
				cout << videoTitle << endl;
			}
		}
		void Subscribe()
		{
			SubscribersCount++;
		}
		void Unsubscribe() 
		{
			if (SubscribersCount > 0)
				SubscribersCount--;
		}
		void PublishVideo(string title) 
		{
			PublishedVideoTitles.push_back(title);
		}
};

class EntertainmentYouTubeChannel: public YouTubeChannel //Derived Class ->EntertainmentYTChannel is going to inherit  YTChannel 
{
public:
	EntertainmentYouTubeChannel(string name, string ownerName): YouTubeChannel(name, ownerName)
	{
		
	}
	void Adventure()
	{
		cout << "traveling, fun, games, pranks..." << endl;
	}
};


int main()
{
	EntertainmentYouTubeChannel EntertainmentytChannel("Family House", "Geez");
	EntertainmentytChannel.PublishVideo("First Child");
	EntertainmentytChannel.PublishVideo("Move-Out Day");
	EntertainmentytChannel.Subscribe();
	EntertainmentytChannel.GetInfo();
	EntertainmentytChannel.Adventure();

	system("pause");
	return 0;
}
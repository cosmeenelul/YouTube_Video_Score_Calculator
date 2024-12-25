#include <iostream>
#include<cstdint>
#include<iomanip>
#include<stdexcept>
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

class Video {
protected:
    string mVideoId;
    uint32_t mLikes, mDislikes, mViews;
    Video(){}
    Video(const string &VideoId, uint32_t Dislikes, uint32_t Likes, uint32_t Views) {
        mVideoId = VideoId;
        mLikes = Likes;
        mDislikes = Dislikes;
        mViews = Views;
    }

public:
    string getId() const {
        return mVideoId;
    }

    uint32_t getDislikes() const {
        return mDislikes;
    }

    double getSimpleScore() const
    {
        return (double) mLikes / mDislikes + 1 - (double) 1 / mViews;
    }
    virtual double getAdvancedScore() const =0;
    void print(bool simple) const
    {
        cout<<mVideoId<<" ";
        if(simple==true)
        {
            cout<<fixed<<setprecision(2)<<getSimpleScore();
        }
        else
        {
            cout<<fixed<<setprecision(2)<<getAdvancedScore();
            cout<<endl;
        }
    }
};
class StudyVideo:public Video
{   public:
    StudyVideo(const string &VideoId,uint32_t Dislikes,uint32_t Likes,uint32_t Views): Video(VideoId,Dislikes,Likes,Views)
    {}
    double getAdvancedScore() const override
    {
        return getSimpleScore()*2.00;
    }
};
class AnimalVideo:public Video
{   public:
    AnimalVideo(const string &VideoId,uint32_t Dislikes,uint32_t Likes,uint32_t Views): Video(VideoId,Dislikes,Likes,Views)
    {}
    double getAdvancedScore() const override
    {
        return getSimpleScore()*0.75;
    }
};
class SportsVideo:public Video
{   public:
    SportsVideo(const string &VideoId,uint32_t Dislikes,uint32_t Likes,uint32_t Views): Video(VideoId,Dislikes,Likes,Views)
    {}
    double getAdvancedScore() const override
    {
        return getSimpleScore()*0.5;
    }
};
class VideoFactory: public Video
{   public:
    VideoFactory():Video(){}
    static Video *createVideo(string &id,string &type,uint32_t likes,uint32_t dislikes,uint32_t views)
    {
        if(type == "Animale")
        {
            AnimalVideo *animalVideo=new AnimalVideo(id,dislikes,likes,views);
            return animalVideo;
        }

        if(type=="Studiu")
        {
            StudyVideo *studyVideo=new StudyVideo(id,dislikes,likes,views);
            return studyVideo;
        }
        if(type=="Sport")
        {
            SportsVideo *sportsVideo=new SportsVideo(id,dislikes,likes,views);
            return sportsVideo;
        }
    }
};
bool comparator(Video *video1,Video *video2)
{
    if(video1->getSimpleScore()<video2->getSimpleScore())
        return true;
    if(video1->getSimpleScore()>video2->getSimpleScore())
        return false;
    if(video1->getSimpleScore()==video2->getSimpleScore())
    {
        if(video1->getDislikes()>video2->getDislikes())
        {
            return true;
        }
            return false;
    }
}
int main() {
    int n;
    vector<Video *> videoclipuri;
    vector<string> types;
    int i;
    string id, type;
    uint32_t likes, dislikes, views;
    cin >> n;
    char cerinta;
    for (i = 0; i < n; i++) {
        cin >> id >> type;
        if (type == "Studiu") {
            types.push_back(type);
            cin >> views >> likes >> dislikes;
            videoclipuri.push_back(new StudyVideo(id, dislikes, likes, views));
        } else if (type == "Animale") {
            types.push_back(type);
            cin >> views >> likes >> dislikes;
            videoclipuri.push_back(new AnimalVideo(id, dislikes, likes, views));
        } else if (type == "Sport") {
            types.push_back(type);
            cin >> views >> likes >> dislikes;
            videoclipuri.push_back(new SportsVideo(id, dislikes, likes, views));
        }

    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin>>cerinta;
    if (cerinta == 'a') {
        std::sort(videoclipuri.begin(), videoclipuri.end(), comparator);
        for (i = 0; i < videoclipuri.size(); i++) {
            if (i == videoclipuri.size() - 1) {
                videoclipuri[i]->print(1);
            } else {
                videoclipuri[i]->print(1);
                cout << endl;
            }

        }
    } else if (cerinta == 'b') {
        int k = 0;
        double medie = 0;
        for (i = 0; i < videoclipuri.size(); i++) {
            medie += videoclipuri[i]->getSimpleScore();
            k++;
        }
        medie = medie / k;
        for (i = 0; i < videoclipuri.size(); i++) {
            if (videoclipuri[i]->getSimpleScore() > medie && i == videoclipuri.size() - 1) {
                videoclipuri[i]->print(true);
            } else if (videoclipuri[i]->getSimpleScore() > medie) {
                videoclipuri[i]->print(true);
                cout << endl;
            }
        }
    } else if (cerinta == 'c') {
        while (cin >> id >> type >> views >> likes >> dislikes)
        {
            if(type=="Studiu")
            {
                int poz;
                poz=-1;
                for(i=0;i<videoclipuri.size();i++)
                {
                    if(videoclipuri[i]->getId()==id && types[i]==type)
                    {
                        poz=i;
                    }
                }
                if(poz!=-1)
                {
                    delete videoclipuri[i];
                    videoclipuri[i]=new StudyVideo(id,dislikes,likes,views);
                }
                else
                {
                    videoclipuri.push_back(new StudyVideo(id,dislikes,likes,views));
                }
            } else if(type=="Animale")
            {

                int poz;
                poz=-1;
                for(i=0;i<videoclipuri.size();i++)
                {
                    if(videoclipuri[i]->getId()==id && types[i]==type )
                    {
                        poz=i;
                    }
                }
                if(poz!=-1)
                {   delete videoclipuri[i];
                    videoclipuri[i]=new AnimalVideo(id,dislikes,likes,views);
                }
                else
                {
                    videoclipuri.push_back(new AnimalVideo(id,dislikes,likes,views));
                }
            } else if(type=="Sport" && types[i]==type)
            {
                int poz;
                poz=-1;
                for(i=0;i<videoclipuri.size();i++)
                {
                    if(videoclipuri[i]->getId()==id)
                    {
                        poz=i;
                    }
                }
                if(poz!=-1)
                {   delete videoclipuri[i];
                    videoclipuri[i]=new SportsVideo(id,dislikes,likes,views);
                }
                else
                {
                    videoclipuri.push_back(new SportsVideo(id,dislikes,likes,views));
                }

            }
        }
        sort(videoclipuri.begin(), videoclipuri.end(),comparator);

        for(i=0;i<videoclipuri.size();i++)
        {   cout<<endl;
            if(i==videoclipuri.size()-1)
            {
                videoclipuri[i]->print(true);
            }
            else
            {
                videoclipuri[i]->print(true);
            }
        }
    }
    else if (cerinta == 'd') {
            std::sort(videoclipuri.begin(), videoclipuri.end(), comparator);
            for (i = 0; i < videoclipuri.size(); i++) {
                if (i == videoclipuri.size() - 1) {
                    videoclipuri[i]->print(false);
                } else {
                    videoclipuri[i]->print(false);
                }
            }
    }
    return 0;
}
#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
srand((unsigned)time(0))
struct Ability
{
    int scores[6],modifiers[6];
};

struct weapons
{
    int attack_base;
    char name[20],allow;
};

class Races_Classes
{
    //protected:
        Ability ab;
        weapons ranged,melee;
        char race_name[15],class_name[10];
        int hitpts,heal,max_hitpts,gold;
    public:
        Races_Classes()
        {
            max_hitpts=hitpts=heal=0;
            gold=50;
            for(int i=0;i<6;i++)
            {
                ab.scores[i]=0;
                ab.modifiers[i]=0;
            }
        }

        void display()
        {
            //cout<<"\nRace number: "<<race_no;
        }

        void assignAbility()
        {
            int data,val[]={15,14,13,12,10,8};
            cout<<"\nAssign scores to ability(15,14,13,12,10,8)";
            cout<<"\nEnter the order:\n1.Strength  2.Constitution  3.Dexterity  4.Wisdom  5.Intelligence  6.Charisma";
            for(int i=0;i<6;)
            {
                cin>>data;
                switch(data)
                {
                    case 1:if(ab.scores[0]==0){ab.scores[0]=val[i];i++;}break;
                    case 2:if(ab.scores[1]==0){ab.scores[1]=val[i];i++;}break;
                    case 3:if(ab.scores[2]==0){ab.scores[2]=val[i];i++;}break;
                    case 4:if(ab.scores[3]==0){ab.scores[3]=val[i];i++;}break;
                    case 5:if(ab.scores[4]==0){ab.scores[4]=val[i];i++;}break;
                    case 6:if(ab.scores[5]==0){ab.scores[5]=val[i];i++;}break;
                }
            }
        }

        void assignClass()
        {
            int data;
            cout<<"\nEnter your choice of class:\n1.Cleric  2.Fighter  3.Ranger  4.Rogue";
            do
            {cin>>data;}while(data<1 || data>4);
            switch(data)
            {
                case 1: strcpy(class_name,"Cleric");
                        max_hitpts=12;
                        heal=7;
                        ranged.allow='Y';
                        melee.allow='Y';
                        ab.modifiers[2]-=1;break;
                case 2: strcpy(class_name,"Fighter");
                        max_hitpts=15;
                        heal=9;
                        ranged.allow='Y';
                        melee.allow='Y';
                        ab.modifiers[0]+=1;
                        ab.modifiers[2]+=1;break;
                case 3: strcpy(class_name,"Ranger");
                        max_hitpts=12;
                        heal=6;
                        ranged.allow='Y';
                        melee.allow='Y';
                        ab.modifiers[0]-=1;break;
                case 4: strcpy(class_name,"Rogue");
                        max_hitpts=12;
                        heal=6;
                        ranged.allow='Y';
                        melee.allow='N';
                        ab.modifiers[2]+=1;break;
            }
        }

        void assignRace()
        {
            int data;
            cout<<"\nEnter your choice of Race\n1.Dragonborn  2.Dwarf  3.Elf  4.Human  5.Trefling";
            do
            {cin>>data;}while(data<1 || data>5);
            switch(data)
            {
                case 1: strcpy(race_name,"Dragonborn");
                        ab.scores[0]+=2;
                        ab.scores[5]+=2;
                        strcpy(melee.name,"Short-Sword");
                        melee.attack_base=6;
                        strcpy(ranged.name,"Dagger");
                        ranged.attack_base=4;
                        break;
                case 2: strcpy(race_name,"Dwarf");
                        ab.scores[3]+=2;
                        ab.scores[1]+=2;
                        strcpy(melee.name,"Hand-Axe");
                        melee.attack_base=6;
                        strcpy(ranged.name,"Sling");
                        ranged.attack_base=6;
                        break;
                case 3: strcpy(race_name,"Elf");
                        ab.scores[2]+=2;
                        ab.scores[3]+=2;
                        strcpy(melee.name,"Sickle");
                        melee.attack_base=6;
                        strcpy(ranged.name,"Cross-bow");
                        ranged.attack_base=6;
                        break;
                case 4: strcpy(race_name,"Human");
                        cout<<"\nYou can add 2 pts to an Ability Score:\n1.Strength  2.Constitution  3.Dexterity  4.Wisdom  5.Intelligence  6.Charisma";
                        do{cin>>data;}while(data<1 || data>6);
                        ab.scores[data]+=2;
                        strcpy(melee.name,"Club");
                        melee.attack_base=6;
                        strcpy(ranged.name,"Dagger");
                        ranged.attack_base=4;
                        break;
                case 5: strcpy(race_name,"Trefling");
                        ab.scores[4]+=2;
                        ab.scores[5]+=2;
                        strcpy(melee.name,"Scythe");
                        melee.attack_base=4;
                        strcpy(ranged.name,"Spear");
                        ranged.attack_base=8;
                        break;
            }
        }

        void setModifiers()
        {
            for(int i=0;i<6;i++)
            {
                ab.modifiers[i]+=(ab.scores[i]-10)/2;
            }
            max_hitpts+=ab.scores[1];
            heal+=ab.modifiers[1];
            hitpts=max_hitpts;
        }

        void attackMonsters(monsters &mon)
        {
            int mon_armour=mon.getAC();
            int random;
            if(melee.allow=='N' && ranged.allow=='N')
            {
                cout<<"\nYou cannot attack";return;
            }
            int data;
            if(melee.allow=='N')data=2;
            else if(ranged.allow=='N')data=1;
            else
            {
                cout<<"\nEnter the type of attack: 1.Melee 2.Ranged";
                do{cin>>data;}while(data>2 || data<1);
            }
            switch(data)
            {
            case 1: random=20-rand()%20+Ability.modifiers[0];
                    if(random<mon_armour)
                    {
                        cout<<"\n-----IT IS A MISS-----";
                        return;
                    }
                    cout<<"\n-----IT IS A HIT-----";
                    random=melee.attack_base-rand()%melee.attack_base

            }
        }
};

class Players
{
        char name[20];
        Races_Classes RC;
    public:
        Players(const char *s):RC()
        {   strcpy(name,s);}
        void display()
        {
            cout<<"\nPlayer Name: "<<name;
            RC.display();
        }
        void getdata()
        {
            RC.assignAbility();
            RC.assignClass();
            RC.assignRace();
            RC.setModifiers();
        }

};

int main()
{
    Players p("Mukund");
    p.getdata();
}

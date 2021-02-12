#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<time.h>
#include<ncurses.h>
using namespace std;

int sel[6];
int tempp=0;

//下面pokemon定义和实现
//一共6个机灵
class Pokemon
{
public:
    string name;
    string type;
    int level;
    int attack;
    int defense;
    int life;
    int attacktime;
    int experience;
    int experience_lev_up;
    Pokemon()
    {
        name="unknown";
        type="unknown";
        level=0;
        attack=0;
        defense=0;
        life=0;
        attacktime=0;
        experience=0;
        experience_lev_up=0;
    }
    void show();
    virtual    void level_up();
    virtual void attacktype();
};

void Pokemon::show()
{
    cout<<"name："<<name<<endl;
    cout<<"type："<<type<<endl;
    cout<<"level："<<level<<endl;
    cout<<"attack："<<attack<<endl;
    cout<<"defense："<<defense<<endl;
    cout<<"life："<<life<<endl;
    cout<<"attack time："<<attacktime<<endl;
    cout<<"current experience："<<experience<<endl;
    cout<<"increase ："<<experience_lev_up<<endl<<endl;
}

void Pokemon::level_up(){};
void Pokemon::attacktype(){};

void add_pok(); //加入机灵
void check_pok();//查看机灵

void delete_pok(); //删除机灵

class pok_1:public Pokemon
{
public:
    pok_1()
    {
        name="rock";
        type="attack_type";
        level=1;
        attack=60;
        defense=40;
        life=40;
        attacktime=40;
        experience=0;
        experience_lev_up=10;
    }
    void level_up();
    void attacktype();
};


void pok_1::level_up()
{
    level++;
    attack+=20;
    defense+=10;
    life+=10;
    attacktime=attacktime-2;
    experience=experience-experience_lev_up;
    experience_lev_up=level*2;
}

void pok_1::attacktype()
{
    cout<<"hard attack！"<<endl;
}



class pok_2:public Pokemon
{
public:
    pok_2()
    {
        name="undertaker";
        type="defend_type";
        level=1;
        attack=25;
        defense=70;
        life=60;
        attacktime=52;
        experience=0;
        experience_lev_up=10;
    }
    void level_up();
    void attacktype();
};

void pok_2::level_up()
{
    level++;
    attack+=10;
    defense+=20;
    life+=10;
    attacktime=attacktime-2;
    experience=experience-experience_lev_up;
    experience_lev_up=level*2;
}

void pok_2::attacktype()
{
    cout<<"defensive attack！"<<endl;
}



class pok_3:public Pokemon
{
public:
    pok_3()
    {
        name="cat";
        type="high_life";
        level=1;
        attack=35;
        defense=50;
        life=70;
        attacktime=48;
        experience=0;
        experience_lev_up=10;
    }
    void level_up();
    void attacktype();
};

void pok_3::level_up()
{
    level++;
    attack+=10;
    defense+=10;
    life+=20;
    attacktime=attacktime-2;
    experience=experience-experience_lev_up;
    experience_lev_up=level*2;
}

void pok_3::attacktype()
{
    cout<<"boom！"<<endl;
}



class pok_4:public Pokemon
{
public:
    pok_4()
    {
        name="cheetah";
        type="fast_att";
        level=1;
        attack=50;
        defense=40;
        life=50;
        attacktime=25;
        experience=0;
        experience_lev_up=10;
    }
    void level_up();
    void attacktype();
};

void pok_4::level_up()
{
    level++;
    attack+=10;
    defense+=10;
    life+=10;
    attacktime=attacktime-1;
    experience=experience-experience_lev_up;
    experience_lev_up=level*2;
}

void pok_4::attacktype()
{
    cout<<"fast_attack！"<<endl;
}

class pok_5:public Pokemon
{
public:
    pok_5()
    {
        name="cooljoy";
        type="high life";
        level=1;
        attack=40;
        defense=40;
        life=63;
        attacktime=35;
        experience=0;
        experience_lev_up=10;
    }
    void level_up();
    void attacktype();
};

void pok_5::level_up()
{
    level++;
    attack+=10;
    defense+=10;
    life+=10;
    attacktime=attacktime-1;
    experience=experience-experience_lev_up;
    experience_lev_up=level*2;
}

void pok_5::attacktype()
{
    cout<<"cool_attack！"<<endl;
}




class pok_6:public Pokemon
{
public:
    pok_6()
    {
        name="bogzyboy";
        type="strong";
        level=1;
        attack=72;
        defense=50;
        life=40;
        attacktime=40;
        experience=0;
        experience_lev_up=10;
    }
    void level_up();
    void attacktype();
};

void pok_6::level_up()
{
    level++;
    attack+=10;
    defense+=10;
    life+=10;
    attacktime=attacktime-1;
    experience=experience-experience_lev_up;
    experience_lev_up=level*2;
}

void pok_6::attacktype()
{
    cout<<"bogzy attack！"<<endl;
}

Pokemon  *ptr[10];  //instance pointer;

////////测试函数
int main()
{
    system("clear");
    srand(time(0));
    int in=0;
    cout<<"testttt"<<endl<<endl;
    while(1)
    {
        cout<<"1 add_pokemon"<<endl<<"2 check_pokemon"<<endl<<"3 delete_pokemon"<<endl<<"4 quit"<<endl<<endl<<"your choice : "<<endl;
        cin>>in;
        system("clear");
        switch(in)
        {
            case 1:
                add_pok();
                break;
            case 2:
                if(tempp>=1)
                    check_pok();
                
                else
                    cout<<"you dont have any pokemons！"<<endl;
                break;
            
            case 3:
                if(tempp>0)
                    delete_pok();
                else
                    cout<<"you dont have any pokemons to delete！"<<endl;
                break;
            case 4:
                cout<<"bye bye！"<<endl;
                exit(1);
                break;
                
            default:
                cout<<"wrong input！"<<endl;
        }
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        system("clear");
    }
    return 0;
}

void add_pok()
{
    int in;
    
select:
    cout<<"select your pokemon："<<endl;
    cout<<"1-rock  2-undertaker 3-cat 4-cheetah 5-cooljoy 6-bogzyboy"<<endl;
    cin>>in;
    for(int j=0;j<6;j++)
    {
        if(sel[j]==in)
        {
            cout<<"you already have that pokemon,choose another"<<endl;
            system( "read -n 1 -s -p \"Press any key to continue...\"" );
            system("clear");
            goto select;
        }
    }
    switch(in)
    {
        case 1:
            sel[0]=1;
            cout<<"added rock！"<<endl;
            ptr[tempp]=new pok_1;
            tempp++;
            
            break;
        case 2:
            sel[1]=2;
            cout<<"added undertaker！"<<endl;
            ptr[tempp]=new pok_2;
            tempp++;
            
            break;
           
        case 3:
            sel[2]=3;
            cout<<"added super cat！"<<endl;
            ptr[tempp]=new pok_3;
            tempp++;
                        break;
        case 4:
            sel[3]=4;
            cout<<"added cheetah！"<<endl;
            ptr[tempp]=new pok_4;
            tempp++;
            break;
        case 5:
            sel[4]=5;
            cout<<"added cooljoy !"<<endl;
            ptr[tempp]=new pok_5;
            tempp++;
            
        case 6:
            sel[5]= 6;
            cout<<"added bogzyboy !"<<endl;
            ptr[tempp]= new pok_6;
            tempp++;
            
        default:
            cout<<"wrong input"<<endl;
            system( "read -n 1 -s -p \"Press any key to continue...\"" );
            system("clear");
            goto select;
    }
}



void check_pok()
{
    system("clear");
    cout<<"currently you have "<<tempp<<" pokemons"<<endl;
    
 

        for(int il=0;il<tempp;il++)
        {
            cout<<" "<<il+1<<" pokemon is："<<endl;
            ptr[il]->show();
        }
    
    
}



void delete_pok()
{
    int in=0;
    while(1)
    {
        cout<<"delete pok number : "<<endl;
        cin>>in;
        in--;
        if((in>=0)&&(in<tempp))
        {
            for(int j=in;j<tempp;j++)
            {
                ptr[j]=ptr[j+1];
            }
            break;
        }
        else
            cout<<"wrong input！"<<endl;
    }
    cout<<"deleted succesfully！"<<endl;
    ptr[tempp]=NULL;
    tempp--;
    
}



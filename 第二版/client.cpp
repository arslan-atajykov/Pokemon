
#include<iostream>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<curses.h>     //unix 文件
#include<ncurses.h>    //unix 文件
#include<ctime>
#include<cstdlib>

#define PORT 5437
using namespace std;

char buff[20];  //temp buff
int sel[6];
int in_1;
int tem_p;
int temmmp=0;

//下面是pokemon 信息
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

void add_pok();
void check_pok();

void delete_pok();

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



Pokemon  *ptr[10];




int main()
{
    
    system("clear");
    //unsigned int ival;
    char anyk;
    int client_socket,conn;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    
    //下面是client socket 实现
    
    client_socket = socket (AF_INET, SOCK_STREAM,0);
    if(client_socket <0)
    {
        std::cout<<"error in connection.\n";
        exit(1);
    }
    std::cout<<"client socket is created \n";
    
    memset(&serv_addr,'0',sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr= inet_addr("127.0.0.1");
    serv_addr.sin_port=htons(PORT);
    
    conn = connect(client_socket ,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    
    char exit_key[50];
    
    if(conn<0)
    {
        std::cout<<"error in connection\n";
        exit(1);
    }
    std::cout<<" connected to server \n";
    
    while (1)
    {
        //这是注册和login 操作
        //如果1 就注册,2就login
        
        char key[2];
        
        cout<<"choose 1 to register"<<endl <<"choose 2 to login  "<<endl;
        cout<<"your choice : ";
        
    Login:
        
        cin>>key[0];
        cin.ignore();
        
        if((key[0])=='1')
        {
            buffer[0]=key[0];
            send(client_socket,buffer,1,0);
            
            char new_us[50];
            char new_pass[50];
            
            
            
            
            
            if(strcmp(buffer,":exit")==0)
            {
                close (client_socket);
                std::cout<<"disconnected from server.\n";
                exit(1);
            }
            if(recv(client_socket,buffer,1024,0)<0)
            {
                std::cout<<"error in receiving data.\n";
                
            }
            else    {
                system("clear");
                printf("%s",buffer);
                
                //cout<<"enter new username : ";
            lab:  cin>>new_us;
                cin.ignore();
                bzero(buffer,sizeof(buffer));
                strcpy(buffer,new_us);
                send(client_socket,buffer,strlen(buffer),0);
                
                
                
                recv(client_socket,buffer,1024,0);
                
                if(strlen(buffer)>=54)
                {
                    
                    cout<<buffer;
                    
                    cout<<"\nusername : ";
                    goto lab;
                }
                
                
                
                
                
                
                cout<<buffer;
                cin>>new_pass;
                strcpy(buffer,new_pass);
                send(client_socket,buffer,strlen(buffer),0);
                
                
                //注册成功后随机给三个机灵
                
                
                /////////////////////////////////
                srand((unsigned)time(NULL));
                
                while(temmmp<2)
                {
                rand:  in_1=(rand()%6)+1;
                    if(temmmp==3)
                        break;
                    cout<<endl<<in_1<<endl;
                    cout<<temmmp<<endl;
                    for(int lj=0;lj<6;lj++)
                    {
                        if(sel[lj]==in_1)
                        {
                            //cout<<"you already have that pokemon,choose another"<<endl;
                            
                            //system("clear");
                            goto rand;
                        }
                    }
                select:
                    switch(in_1)
                    {
                        case 1:
                            sel[0]=1;
                            ptr[temmmp]=new pok_1;
                            temmmp++;
                            goto rand;
                        case 2 :
                            sel[1]=2;
                            ptr[temmmp]=new pok_2;
                            temmmp++;
                            goto rand;
                        case 3 :
                            sel[2]=3;
                            ptr[temmmp]=new pok_3;
                            temmmp++;
                            goto rand;
                        case 4:
                            sel[3]=4;
                            ptr[temmmp]=new pok_4;
                            temmmp++;
                            goto rand;
                        case 5:
                            sel[4]=5;
                            ptr[temmmp]=new pok_5;
                            temmmp++;
                            goto rand;
                        case 6:
                            sel[5]= 6;
                            ptr[temmmp]= new pok_6;
                            temmmp++;
                            goto rand ;
                        default:
                            break;
                            
                            
                    }
                    
                }
                cout<<ptr[0]->name<<endl;
                buff[0]='\0';
                strcpy(buff,ptr[0]->name.c_str());
                //cout<<endl<<buff<<endl;
                bzero(buffer,sizeof(buffer));
                strcpy(buffer,buff);
                send (client_socket,buffer,sizeof(buffer),0);
                
                buff[0]='\0';
                strcpy(buff,ptr[1]->name.c_str());
                //cout<<endl<<buff<<endl;
                bzero(buffer,sizeof(buffer));
                strcpy(buffer,buff);
                send (client_socket,buffer,sizeof(buffer),0);
                
                buff[0]='\0';
                strcpy(buff,ptr[2]->name.c_str());
                //cout<<endl<<buff<<endl;
                bzero(buffer,sizeof(buffer));
                strcpy(buffer,buff);
                send (client_socket,buffer,sizeof(buffer),0);
                
                /*
                 bzero(buffer,sizeof(buffer));
                 recv(client_socket,buffer,1024,0);
                 ival=0;
                 ival=*(unsigned int*)(buffer);
                 
                 for(int ki=0; ki<sizeof(unsigned int); ki++)
                 printf("%02X ", buffer[ki]);
                 
                 std::cout<<endl<<ival<<endl;
                 bzero(buffer,sizeof(buffer));
                 tem_p=ival-1;
                 */
                /////////////////////////////////////
                
                
                recv(client_socket,buffer,1024,0);
                system("clear");
                cout<<buffer;
                cin>>exit_key;
                std::cin.ignore();
                strcpy(buffer,exit_key);
                send(client_socket,buffer,strlen(buffer),0);
                if(strcmp(buffer,":exit")==0)
                {
                    close (client_socket);
                    std::cout<<"disconnected from server.\n";
                    
                }
                else{
                    system("clear");
                    goto console_window;
                }
            }
        }
        else if(key[0]=='2')
        {
            buffer[0]=key[0];
            send(client_socket,buffer,1,0);
            cout<<"login"<<endl;
            char username[50];
            char password[50];
            if(strcmp(buffer,":exit")==0)
            {
                close (client_socket);
                std::cout<<"disconnected from server.\n";
                exit(1);
            }
            if(recv(client_socket,buffer,1024,0)<0)
            {
                std::cout<<"error in receiving data.\n";
                
            }
            
            else    {
            Login_name:
                
                // cout<<"username : ";
                system("clear");
                printf("%s ",buffer);
                cin>>username;
                
                cin.ignore();
                bzero(buffer,sizeof(buffer));
                strcpy(buffer,username);
                
                send(client_socket,buffer,strlen(buffer),0);
                
                
                //  recv(client_socket,buffer,1024,0);
                
                
                
                
                
                recv(client_socket,buffer,1024,0);
                // cout<<buffer;
                if(strlen(buffer)>=30)
                {
                    // bzero(buffer,sizeof(buffer));
                    //recv(client_socket,buffer,1024,0);
                    goto Login_name;
                }
                cout<<buffer;
            Login_pass:    // bzero(buffer,sizeof(buffer);
                cin>>password;
                cin.ignore();
                bzero(buffer,sizeof(buffer));
                strcpy(buffer,password);
                send(client_socket,buffer,strlen(buffer),0);
                
                
                recv(client_socket,buffer,1024,0);
                system("clear");
                //cout<<buffer;
                if(strlen(buffer)>=56)
                {
                    cout<<"heyyyy,wronggg\n";
                    cout<<"enter the password again : ";
                    goto Login_pass;
                }
                
                else if(strlen(buffer)<=45)
                {
                    system("clear");
                    cout<<buffer;
                    cin>>anyk;
                    goto console_window;///////////////////////////
                }
                
                
                
                
                
                
            }
        }
        
    }
console_window:
    while(1)
    {
        //main console window
        char in[5];
    choose:
        //system("clear");
        cout<<"\nenter 1 start is not working now\nenter 2 to see online players\nenter 3 to see players info \nenter 4 to quit the game\n";
        cout<<"your choice: ";
        
        cin>> in;
        cin.ignore();
        //system("clear");
        
        switch(in[0])
        {
            case '1':
                cout<<"start\ngame finished,bye bye";
                
                exit (1);
                
            case '2':
                // cout<<"online players";
                bzero(buffer,sizeof(buffer));
                send(client_socket,"2",1,0);
                system("clear");
                cout<<"online players       total games  "<<endl<<endl;
                while(1)
                {
                    recv(client_socket,buffer,1024,0);
                    
                    if(strcmp(buffer,"p")==0)
                    {
                        //cout<<"cool";
                        
                        break;                     }
                    //cout<<"buffer is \n";
                    cout<<buffer<<"\n";
                    bzero(buffer,sizeof(buffer));
                    //cout<<buffer;
                    //cout<<endl;
                    
                }
                bzero(buffer,sizeof(buffer));
                cout<<"\nenter any key to go back : ";
                cin>>in;
                system("clear");
                strcpy(buffer,in);
                send(client_socket,buffer,sizeof(buffer),0);
                if(strcmp(buffer,"quit")==0)
                {
                    close(client_socket);
                    exit(1);
                    break;
                }
                goto choose;
            case '3':
                //cout<<"check all players pokemons";
                bzero (buffer,sizeof(buffer));
                send(client_socket,"kimki",5,0);
                system("clear");
                cout<<"players             pokemons  "<<endl<<endl;
                while(1)
                {
                    recv(client_socket,buffer,1024,0);
                    
                    if(strcmp(buffer,"p")==0)
                    {
                        //cout<<"cool";
                        
                        break;
                        
                    }
                    //cout<<"buffer is \n";
                    
                    cout<<buffer<<"\n";
                    bzero(buffer,sizeof(buffer));
                    //cout<<buffer;
                    //cout<<endl;
                    
                }
                bzero(buffer,sizeof(buffer));
                cout<<"\nenter any key to go back : ";
                cin>>in;
                system("clear");
                strcpy(buffer,in);
                send(client_socket,buffer,sizeof(buffer),0);
                if(strcmp(buffer,"quit")==0)
                {
                    close(client_socket);
                    exit(1);
                    break;
                }
                goto choose;
                
                
            case '4':
                system("clear");
                cout<<"quit";
                bzero(buffer,sizeof(buffer));
                send(client_socket,"bye bye ",8,0);
                close(client_socket);
                exit(1);
            default:
                system("clear");
                cout<<"wrong input\n";
                goto choose;
                
        }
        
    }
    return 0;
    
    
    
}

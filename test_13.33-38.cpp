#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
class Folder; 
class Message{
   friend class Folder;
   friend void swap(Message&,Message&);
	  private: 
	    string contents; 
	    set<Folder*>folders; 
	    void add_to_Folders(const Message&);
	    void remove_from_Folders(const Message&); 
	  public: 
	    Message(const string& s=" "):contents(s){}  //构造函数
 
        //拷贝控制成员，用来管理指向本message的指针
        Message(const Message&msg);  
        Message& operator=(Message&);  
        ~Message(); 
	    //从给定folder中添加/删除message
	    void save(Folder&); 
	    void remove(Folder&);
	    void addFolders( Folder&fol){folders.insert(&fol);} 
	    void removeFolders(Folder&fol){folders.erase(&fol);}


};



class Folder{
	  private: 
	    set<Message*>Messages; 
	  public: 
	     Folder()=default;
	    void addMsg(Message&msg){Messages.insert(&msg);} 
	    void remMsg(Message&msg){Messages.erase(&msg);} 
       
};


void swap(Message& msga,Message &msgb)
{

    using std::swap;
   msga.remove_from_Folders(msga);   //将所有message中对应floder中删除
   msgb.remove_from_Folders(msgb);    
   msgb.add_to_Folders(msga);   //需要交换信息的指针加入原Folders中
   msga.add_to_Folders(msgb);
   swap(msgb.folders,msga.folders);
	
} 


void Message::add_to_Folders(const Message &msg)
{
	for(auto i:msg.folders)
	 {
	 	i->addMsg(*this);
	 } 
}

void Message::remove_from_Folders(const Message &msg) 
{
	for(auto i:msg.folders)
	{
		i->remMsg(*this); 
	} 
}


Message::Message(const Message&msg):contents(msg.contents),folders(msg.folders)
{
	 add_to_Folders(msg); 
}

Message::~Message()
{
	remove_from_Folders(*this);
}

Message& Message::operator=(Message &msg)
{
    remove_from_Folders(*this);
    contents=msg.contents; 
    folders=msg.folders;
    add_to_Folders(*this);

    return*this;
}

void  Message::save(Folder&fol)
{
    folders.insert(&fol);
    fol.addMsg(*this);


}

void Message::remove(Folder &fol)
{
	folders.erase(&fol);
    fol.remMsg(*this);
}

int main() 
{
	
}


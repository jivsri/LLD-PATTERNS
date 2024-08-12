#include<bits/stdc++.h>
using namespace std;

class Observer{
    public:
    virtual void update(){};
};



class ObservableInterface{
    public:
    virtual void add(Observer*)=0;
    virtual void remove(Observer*)=0;
    virtual void getData()=0;
    virtual void notify()=0;
    virtual void setData(int)=0;
};

class IphoneStockObservable:public ObservableInterface{
    public:
    int stock;
    vector<Observer*> observerList;
    IphoneStockObservable(){
        stock=0;
    }
    void add(Observer *obj){
        observerList.push_back(obj);
    }

    void remove(Observer *obj){
        // remove krne ka logic
    }

    void getData(){
        cout<<"Stock count: "<<stock<<endl;
    }

    void notify(){
        for(auto it:observerList){
            it->update();
        }
    }

    void setData(int val){
        if(stock==0){
            notify();
        }
        stock+=val;
    }
};

class EmailAlertObserver:public Observer{
    string emailId;
    ObservableInterface * obj;
    public:
    EmailAlertObserver(string email,ObservableInterface * ptr){
        emailId=email;
        obj=ptr;
    }
    void sendMail(){
        cout<<"mail sent to "<<emailId<<endl;
    }
    void update(){
        sendMail();
    }
};


class MobileAlertObserver:public Observer{
    string Id;
    ObservableInterface * obj;
    public:
    MobileAlertObserver(string id,ObservableInterface * ptr){
        Id=id;
        obj=ptr;
    }
    void sendNotif(){
        cout<<"mail sent to "<<Id<<endl;
    }
    void update(){
        sendNotif();
    }
};


int main(){
    ObservableInterface *obj=new IphoneStockObservable();
    Observer *user=new EmailAlertObserver("abc@gmail.com",obj);
    Observer *user2=new EmailAlertObserver("abcd@gmail.com",obj);
    Observer *user3=new MobileAlertObserver("mera phone 1",obj);

    obj->add(user);
    obj->add(user2);
    obj->add(user3);

    obj->setData(5);


    return 0;
}
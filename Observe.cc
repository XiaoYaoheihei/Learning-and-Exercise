#include <iostream>
#include <string>
#include <list>
using namespace std;

//定义了一个观察者的基类
class IObserve {
  public:
    virtual ~IObserve() {};                     //析构函数
    virtual void Update(const string &message_from_subject) = 0; 
                                                //更新消息
};
//定义了一个发布者的基类
class ISubject {
  public:  
    virtual ~ISubject() {};                     //析构函数
    virtual void Attach(IObserve *observer) = 0;//增加观察者
    virtual void Detach(IObserve *observer) = 0;//移除观察者
    virtual void Notify() = 0;                  //通知消息更改
};


//发布者
class Subject : public ISubject {
  public:
    virtual ~Subject() {
        cout << "goodbye,i was the subject." << endl;
    }
    //订阅管理方法
    //增加观察者
    void Attach(IObserve *observe) override {
        list_observer_.push_back(observe);
    }
    //移除观察者
    void Detach(IObserve *observe) override {
        list_observer_.remove(observe);
    }
    //开始通知每一个观察者
    void Notify() override {
        //从观察者容器里面遍历每一个观察者
        list<IObserve *>::iterator iterator = list_observer_.begin();
        HowManyObserver();
        while (iterator != list_observer_.end()) {
            (*iterator)->Update(message_);
            ++iterator;
        }
    }
    //CreatMessage函数有默认参数
    void CreatMessage(string message = "empty") {
        this->message_ = message;
        //信息更新完成之后，会调用Notify函数进行通知
        Notify();
    }
    //判断多少名观察者的方法
    void HowManyObserver() {
        cout << "there are " << list_observer_.size() << " observers in the list" << endl;
    }
  private:
    string message_;                    //消息定义
    list<IObserve *> list_observer_;    //观察者容器
                                        //每个观察者只会有一个观察者容器
};

//观察者
class Observe : public IObserve {
  public:
    virtual ~Observe() {
        cout << "goodbye, i was the observer \"" << this->number_ << endl;
    }
    //观察者的所有方法
    //将自身从观察者容器中移除
    void RemoveMeFromTheList();       
    //打印信息          
    void PrintInfo();                        
    //观察者初始化（先用初始化列表初始化）
    Observe(Subject &subject) : subject_(subject) { 
        this->subject_.Attach(this);
        cout << "Hi, I'm the Observer \"" << ++Observe::static_number_ << "\".\n";
        this->number_ = Observe::static_number_;
    }
    //更新消息
    void Update(const string &message_from_subject) override {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }
  private:
    int number_;                    //数字
    static int static_number_;      //序号
    string message_from_subject_;   //从发布者那里读取的消息
    Subject &subject_;              //对哪一个发布者进行观察
};
void Observe::RemoveMeFromTheList() {
    subject_.Detach(this);
    std::cout << "Observer \"" << number_ << "\" removed from the list." << endl;
}
void Observe::PrintInfo() {
    cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << endl;
}
//观察者的静态局部变量
int Observe::static_number_ = 0;

void ClientCode() {
    //初始化发布者
    Subject *subject = new Subject;
    Observe *observe1 = new Observe(*subject); 
    Observe *observe2 = new Observe(*subject);
    Observe *observe3 = new Observe(*subject);
    //初始化完成之后，首先把observe1，2,3添加到观察者列表当中去
    Observe *observe4;
    Observe *observe5;

    //当对发布者的信息进行更改的时候，发布者会逐一通知观察者新的消息
    //当把观察者移除发布者列表的时候，发布者会进行相应的操作
    subject->CreatMessage("hello world : d");
    observe3->RemoveMeFromTheList();

    //此前只是定义了observe4和observe5，并没有进行初始化
    subject->CreatMessage("the weather is hot today!");
    observe4 = new Observe(*subject);

    observe2->RemoveMeFromTheList();
    observe5 = new Observe(*subject);
    
    subject->CreatMessage("my new car is great!");
    observe5->RemoveMeFromTheList();

    observe4->RemoveMeFromTheList();
    observe1->RemoveMeFromTheList();

    delete observe5;
    delete observe4;
    delete observe3;
    delete observe2;
    delete observe1;
    delete subject;
}
   
int main() {
    ClientCode();
    return 0;
}
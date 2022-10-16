#include"OptionsParcer.h"

class HandlerFilterdir{
public:
    HandlerFilterdir():m_next(nullptr){}

    void add(HandlerFilterdir* new_filter){
        if(m_next){
            m_next->add(new_filter);
        }
        else {
            m_next = new_filter;
        }
    }

    virtual void exec(const std::string& line){
        if(m_next){
            m_next->exec(line);
        }
    }
private:
    HandlerFilterdir* m_next;
};

class IncludeFilterdir:public HandlerFilterdir{
public:
    void exec(const std::string& line) override{
        if(line.find("dd")==0){
            // chain doesn't throw
        }
        else{
            // chain throw
            HandlerFilterdir::exec(line);
        }
    }
};



class FileGetter{
public:
    FileGetter(OptionsParcer* opt_parcer):opt_parcer(opt_parcer){
        
    }
    void setDirectory(){

    }
private:
    std::unique_ptr<OptionsParcer> opt_parcer;    
};
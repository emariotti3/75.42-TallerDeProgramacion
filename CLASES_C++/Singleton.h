#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton{
    private:
        static Singleton *instance;
        Singleton(){}
        Singleton(const Singleton &s);
        void operator=(const Singleton &s);

    public:
        static Singleton* get_instance();
};

#endif //SINGLETON_H

//
// Created by chi on 24/05/06.
//

#ifndef E_COMMERCE_SINGLETONTEMPLATE_H
#define E_COMMERCE_SINGLETONTEMPLATE_H


namespace Service {
    template<typename T>
    class SingletonTemplate {
        static T *instance;
    public:
        static T *getInstance();
    };

    template<typename T>
    T *SingletonTemplate<T>::getInstance() {
        if (!instance)
            instance = new T();
        return instance;
    }

    template<typename T>
    T *SingletonTemplate<T>::instance = nullptr;
}
#endif //E_COMMERCE_SINGLETONTEMPLATE_H

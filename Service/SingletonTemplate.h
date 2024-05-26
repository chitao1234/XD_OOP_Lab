//
// Created by chi on 24/05/06.
//

#ifndef E_COMMERCE_SINGLETONTEMPLATE_H
#define E_COMMERCE_SINGLETONTEMPLATE_H


namespace Service {
    template<typename T>
    class SingletonTemplate {
    public:
        static T *getInstance();
    };

    template<typename T>
    T *SingletonTemplate<T>::getInstance() {
        static T instance;
        return &instance;
    }
}
#endif //E_COMMERCE_SINGLETONTEMPLATE_H

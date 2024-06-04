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

        // 禁止拷贝构造函数和赋值运算符
        SingletonTemplate(const SingletonTemplate &) = delete;

        SingletonTemplate &operator=(const SingletonTemplate &) = delete;

    protected:
        // 使用单例模式，禁止外部创建对象，使用protected修饰，以便派生类可以访问
        SingletonTemplate() = default;

        ~SingletonTemplate() = default;
    };

    template<typename T>
    T *SingletonTemplate<T>::getInstance() {
        static T instance;
        return &instance;
    }
}
#endif //E_COMMERCE_SINGLETONTEMPLATE_H

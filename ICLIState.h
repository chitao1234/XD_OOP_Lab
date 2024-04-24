//
// Created by chi on 24/04/24.
//

#ifndef E_COMMERCE_ICLISTATE_H
#define E_COMMERCE_ICLISTATE_H


class ICLIState {
public:
    virtual ~ICLIState() {};

    virtual void displayMenu() = 0;

    virtual bool handleUserInput() = 0;
};


#endif //E_COMMERCE_ICLISTATE_H

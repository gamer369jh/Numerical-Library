#ifndef ADMIN_H
#define ADMIN_H
#include "account.h"
class admin:public account
{
public:
    admin(int,QString,QString,QString,QString,QString,QString,QString,QString,int,QString,QString,QString);
    ~admin();
};

#endif // ADMIN_H

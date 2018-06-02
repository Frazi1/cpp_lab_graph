#ifndef APPLICATIONEXCEPTION_H
#define APPLICATIONEXCEPTION_H
#include "exception"
#include <QString>
using namespace std;

class ApplicationException : public std::exception
{
private:
    QString _msg;
public:
    ApplicationException(QString msg): exception(), _msg(msg) {

    }
    const char* what() const noexcept override {
        return _msg.toStdString().c_str();
    }
};

#endif // APPLICATIONEXCEPTION_H

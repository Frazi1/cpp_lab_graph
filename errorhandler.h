#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include "exception"
#include <QMessageBox>
#include <QString>

class ErrorHandler
{
private:
    static ErrorHandler* _instance;
public:
    ErrorHandler() {

    }


    static ErrorHandler& GetInstance() {
        if(_instance == nullptr)
            _instance = new ErrorHandler();
        return *_instance;
    }

    void Handle(std::exception& e) {
        QMessageBox::information(0, "error", e.what());
    }

    void Info(QString msg) {
        QMessageBox::information(0, "Info", msg);
    }
};


#endif // ERRORHANDLER_H

#ifndef FRAMETEST_H
#define FRAMETEST_H

#include <QFrame>

namespace Ui {
class Frametest;
}

class Frametest : public QFrame
{
    Q_OBJECT

public:
    explicit Frametest(QWidget *parent = nullptr);
    ~Frametest();

private:
    Ui::Frametest *ui;
};

#endif // FRAMETEST_H

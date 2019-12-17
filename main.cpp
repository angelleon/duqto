#include "mainwindow.hpp"

#include "duqto.hpp"

int main(int argc, char *argv[])
{
    duqto::Duqto dq(argc, argv);
    return dq.exec();
}

#include "s21_viewer.h"

int main(int argc, char *argv[]) {
  QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
  QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
  QCoreApplication::setApplicationName(APPLICATION_NAME);
  QApplication a(argc, argv);
  s21::Facade facade;
  s21::Controller controller(&facade);
  s21::Viewer viewer(&controller);
  viewer.show();

  return a.exec();
}

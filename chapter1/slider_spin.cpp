#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

int main(int argc,char *argv[])
{
        QApplication app(argc,argv);

        QWidget *window = new QWidget;
        window->setWindowTitle("Enter your age");

        QSpinBox *spinBox = new QSpinBox;
        QSlider *slider = new QSlider(Qt::Horizontal);

        spinBox->setRange(0,100);
        slider->setRange(0,100);

        QObject::connect(spinBox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
        QObject::connect(slider,SIGNAL(valueChanged(int)),spinBox,SLOT(setValue(int)));

        spinBox->setValue(50);

        QHBoxLayout *layout = new QHBoxLayout;

        layout->addWidget(spinBox);
        layout->addWidget(slider);

        window ->setLayout(layout);

        window->show();

        return app.exec();
}


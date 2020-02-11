#include "sig_slots_layout.h"


sig_slots_layout::sig_slots_layout(QWidget *parent)
    : QWidget(parent)
{
    mapper = new QSignalMapper(this);

//_______________________________________________________________
    buttonExit      = new QPushButton(QObject::tr("Exit"),      this);
    buttonEnDis     = new QPushButton(QObject::tr("Disable"),   this);
    buttonVertical  = new QPushButton(QObject::tr("Vertical"),  this);
    buttonHorizontal= new QPushButton(QObject::tr("Horizontal"),this);
    buttonGrid      = new QPushButton(QObject::tr("Grid"),      this);
    buttonStacked   = new QPushButton(QObject::tr("Stacked"),   this);

//_______________________________________________________________
    spinBox = new QSpinBox(this);

    spinBox->setRange(0, 50);
    spinBox->setValue(10);
    //spinBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

//_______________________________________________________________
    slider = new QSlider(this);

    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0, 50);
    slider->setSliderPosition(15);
    slider->setTickPosition(QSlider::TicksAbove);
    slider->setTickInterval(5);
    slider->setSingleStep(1);

//_______________________________________________________________
    lineEdit = new QLineEdit(this);

    lineEdit->setValidator(new QIntValidator(0, 50));
    lineEdit->setText(QString::number(15));

//_______________________________________________________________
    label = new QLabel(QString::number(0), this);

    label->setFrameStyle(3);
    label->setMinimumWidth(50);
    label->setText("Not set");
    label->setAlignment(Qt::AlignCenter);
    //label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

//_______________________________________________________________
    buttonsLayout = new QVBoxLayout();

    buttonsLayout->addWidget(buttonVertical);
    buttonsLayout->addWidget(buttonHorizontal);
    buttonsLayout->addWidget(buttonGrid);
    buttonsLayout->addWidget(buttonStacked);

//_______________________________________________________________
    hBoxLayout = new QHBoxLayout();

    hBoxLayout->addWidget(spinBox,  0, Qt::AlignCenter);
    hBoxLayout->addWidget(slider,   0, Qt::AlignCenter);
    hBoxLayout->addWidget(lineEdit, 0, Qt::AlignCenter);
    hBoxLayout->addWidget(label,    0, Qt::AlignRight);

//_______________________________________________________________
    vBoxLayout = new QVBoxLayout();

    vBoxLayout->addWidget(spinBox);
    vBoxLayout->addWidget(slider);
    vBoxLayout->addWidget(lineEdit);
    vBoxLayout->addWidget(label);
    vBoxLayout->addItem(new QSpacerItem(0,10, QSizePolicy::Expanding, QSizePolicy::Expanding));

//_______________________________________________________________
    gridLayout = new QGridLayout();

    gridLayout->addWidget(spinBox,  0,0);
    gridLayout->addWidget(slider,   0,1);
    gridLayout->addWidget(lineEdit, 1,0);
    gridLayout->addWidget(label,    1,1);

//_______________________________________________________________
    stackLayout = new QStackedLayout();

    stackLayout->addWidget(spinBox);
    stackLayout->addWidget(slider);
    stackLayout->addWidget(lineEdit);
stackLayout->setStackingMode(QStackedLayout::StackAll);//NN
//_______________________________________________________________
    combo = new QComboBox(this);

    combo->addItem("QSpinBox");
    combo->addItem("QSlider");
    combo->addItem("QLineEdit");
    combo->hide();

////_______________________________________________________________
    demoStackLayout = new QVBoxLayout();

    demoStackLayout->addWidget(combo);
    demoStackLayout->addWidget(label);
    demoStackLayout->addLayout(stackLayout);

//_______________________________________________________________
    connect(buttonExit, SIGNAL (clicked()), this, SLOT (close()));
    connect(spinBox,    SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    connect(slider,     SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    connect(spinBox,    SIGNAL(valueChanged(QString)), lineEdit, SLOT(setText(QString)));
    connect(spinBox,    SIGNAL(valueChanged(int)), label, SLOT(setNum(int)));
    connect(lineEdit,   SIGNAL(textChanged(QString)), this, SLOT(lineEdit_valueChanged(QString)));
    connect(this,       SIGNAL(mySignal(int)), spinBox, SLOT(setValue(int)));


    connect(buttonVertical,     SIGNAL(clicked(bool)), mapper, SLOT(map()));
    connect(buttonHorizontal,   SIGNAL(clicked(bool)), mapper, SLOT(map()));
    connect(buttonGrid,         SIGNAL(clicked(bool)), mapper, SLOT(map()));
    connect(buttonStacked,      SIGNAL(clicked(bool)), mapper, SLOT(map()));

    connect(buttonEnDis, SIGNAL(clicked()), this, SLOT(buttonEnDisCklicked()));

//_______________________________________________________________
    mapper->setMapping(buttonHorizontal,hBoxLayout);
    mapper->setMapping(buttonVertical,  vBoxLayout);
    mapper->setMapping(buttonGrid,      gridLayout);
    mapper->setMapping(buttonStacked,   demoStackLayout);

    connect(mapper, SIGNAL(mapped(QObject*)), this, SLOT(changeLayout(QObject*)));
    connect(combo,  SIGNAL(activated(int)), stackLayout, SLOT(setCurrentIndex(int)));

//_______________________________________________________________
//this->dumpObjectTree();  //NN

    myQFrame = new QFrame(this);
    myQFrame->setFrameStyle(QFrame::Box|QFrame::Sunken);
    frameLayout = new QHBoxLayout(myQFrame);
    frameLayout->addLayout(hBoxLayout);
    frameLayout->addLayout(buttonsLayout);
//this->dumpObjectTree();   //NN
    EDEbuttonsLayout = new QVBoxLayout();
    EDEbuttonsLayout->addWidget(buttonExit);
    EDEbuttonsLayout->addWidget(buttonEnDis);

//_______________________________________________________________
    mainLayout = new QHBoxLayout(this);

    //mainLayout->addLayout(hBoxLayout);
  //  mainLayout->addLayout(frameLayout);//NN
    mainLayout->addWidget(myQFrame);//NN
    mainLayout->addLayout(EDEbuttonsLayout);

    //changeLayout(hBoxLayout);
}

sig_slots_layout::~sig_slots_layout()
{
    delete hBoxLayout;
    delete vBoxLayout;
    delete gridLayout;
    //delete stackLayout;
    delete buttonsLayout;
    delete demoStackLayout;
}

void sig_slots_layout::lineEdit_valueChanged(QString value) {
 //   label->setText("value");
 //   spinBox->setValue(value.toInt());
 //   slider->setSliderPosition(value.toInt());
    int n = value.toInt();
    emit(mySignal(n));

}

void sig_slots_layout::changeLayout(QObject* pNewLayout){
    if(pNewLayout == demoStackLayout){
        combo->setVisible(true);
        //скрываем все элементы управления
        spinBox->hide();
        lineEdit->hide();
        slider->hide();
        //отображаем только текущий
        stackLayout->currentWidget()->show();
        stackLayout->setStackingMode(QStackedLayout::StackOne);
    }
    else{
        combo->setVisible(false);
        stackLayout->setStackingMode(QStackedLayout::StackAll);
    }

//    QLayoutItem* pItem = mainLayout->itemAt(0);//NN
//    mainLayout->removeItem(pItem);    //NN
//    mainLayout->insertLayout(0, static_cast<QLayout *>(pNewLayout));//NN

            QLayoutItem* pItem = frameLayout->itemAt(0);//NN
            frameLayout->removeItem(pItem);    //NN
            frameLayout->insertLayout(0, static_cast<QLayout *>(pNewLayout));//NN

}

void sig_slots_layout::buttonEnDisCklicked(){
    myQFrame->setDisabled(myQFrame->isEnabled());
    if (myQFrame->isEnabled()) {
        buttonEnDis->setText("Disable");}
    else{buttonEnDis->setText("Enable");}
}


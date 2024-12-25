#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QMessageBox>
#include <QTextEdit>
#include <QSpinBox>

using namespace std;

class FlightReservationGUI : public QWidget {
    Q_OBJECT

public:
    FlightReservationGUI(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Flight Reservation System");

        QVBoxLayout *mainLayout = new QVBoxLayout(this);

        QHBoxLayout *locationLayout = new QHBoxLayout();
        QLabel *sourceLabel = new QLabel("Source:");
        QLabel *destLabel = new QLabel("Destination:");
        sourceCombo = new QComboBox();
        destCombo = new QComboBox();

        sourceCombo->addItems({"Brisbane", "Sydney", "Melbourne", "Canberra"});
        destCombo->addItems({"Brisbane", "Sydney", "Melbourne", "Canberra"});

        locationLayout->addWidget(sourceLabel);
        locationLayout->addWidget(sourceCombo);
        locationLayout->addWidget(destLabel);
        locationLayout->addWidget(destCombo);
        mainLayout->addLayout(locationLayout);

        QHBoxLayout *dateLayout = new QHBoxLayout();
        QLabel *dateLabel = new QLabel("Date of Journey:");
        dateEdit = new QDateEdit(QDate::currentDate());
        dateEdit->setCalendarPopup(true);

        dateLayout->addWidget(dateLabel);
        dateLayout->addWidget(dateEdit);
        mainLayout->addLayout(dateLayout);

        QLabel *nameLabel = new QLabel("Passenger Name:");
        nameEdit = new QLineEdit();
        QLabel *ageLabel = new QLabel("Age:");
        ageSpin = new QSpinBox();
        ageSpin->setRange(1, 120);

        QHBoxLayout *detailsLayout = new QHBoxLayout();
        detailsLayout->addWidget(nameLabel);
        detailsLayout->addWidget(nameEdit);
        detailsLayout->addWidget(ageLabel);
        detailsLayout->addWidget(ageSpin);
        mainLayout->addLayout(detailsLayout);

        QLabel *genderLabel = new QLabel("Gender:");
        genderCombo = new QComboBox();
        genderCombo->addItems({"Male", "Female", "Other"});
        mainLayout->addWidget(genderLabel);
        mainLayout->addWidget(genderCombo);

        QLabel *contactLabel = new QLabel("Contact Number:");
        contactEdit = new QLineEdit();
        mainLayout->addWidget(contactLabel);
        mainLayout->addWidget(contactEdit);

        QPushButton *bookButton = new QPushButton("Book Ticket");
        QPushButton *cancelButton = new QPushButton("Cancel Ticket");
        QPushButton *checkButton = new QPushButton("Check Ticket");

        QHBoxLayout *buttonLayout = new QHBoxLayout();
        buttonLayout->addWidget(bookButton);
        buttonLayout->addWidget(cancelButton);
        buttonLayout->addWidget(checkButton);
        mainLayout->addLayout(buttonLayout);

        connect(bookButton, &QPushButton::clicked, this, &FlightReservationGUI::bookTicket);
        connect(cancelButton, &QPushButton::clicked, this, &FlightReservationGUI::cancelTicket);
        connect(checkButton, &QPushButton::clicked, this, &FlightReservationGUI::checkTicket);
    }

private slots:
    void bookTicket() {
        QString source = sourceCombo->currentText();
        QString dest = destCombo->currentText();
        QDate date = dateEdit->date();
        QString name = nameEdit->text();
        int age = ageSpin->value();
        QString gender = genderCombo->currentText();
        QString contact = contactEdit->text();

        if (source == dest) {
            QMessageBox::warning(this, "Error", "Source and destination cannot be the same.");
            return;
        }

        QMessageBox::information(this, "Booking", "Ticket booked successfully:\n" +
                                 "Name: " + name + "\n" +
                                 "Age: " + QString::number(age) + "\n" +
                                 "Gender: " + gender + "\n" +
                                 "Contact: " + contact + "\n" +
                                 "From: " + source + "\n" +
                                 "To: " + dest + "\n" +
                                 "Date: " + date.toString());
    }

    void cancelTicket() {
        QMessageBox::information(this, "Cancellation", "Ticket has been canceled successfully.");
    }

    void checkTicket() {
        QMessageBox::information(this, "Ticket Info", "Displaying ticket details.");
    }

private:
    QComboBox *sourceCombo;
    QComboBox *destCombo;
    QDateEdit *dateEdit;
    QLineEdit *nameEdit;
    QSpinBox *ageSpin;
    QComboBox *genderCombo;
    QLineEdit *contactEdit;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FlightReservationGUI window;
    window.show();

    return app.exec();
}

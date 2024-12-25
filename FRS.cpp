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

class FlightReservationGUI : public QWidget {
    Q_OBJECT

public:
    FlightReservationGUI(QWidget* parent = nullptr) : QWidget(parent) {
        setWindowTitle("Flight Reservation System");

        // Main layout
        QVBoxLayout* mainLayout = new QVBoxLayout(this);

        // Source and destination selection
        QHBoxLayout* locationLayout = new QHBoxLayout();
        QLabel* sourceLabel = new QLabel("Source:");
        QLabel* destLabel = new QLabel("Destination:");
        QComboBox* sourceCombo = new QComboBox();
        QComboBox* destCombo = new QComboBox();

        sourceCombo->addItems({ "Brisbane", "Sydney", "Melbourne", "Canberra" });
        destCombo->addItems({ "Brisbane", "Sydney", "Melbourne", "Canberra" });

        locationLayout->addWidget(sourceLabel);
        locationLayout->addWidget(sourceCombo);
        locationLayout->addWidget(destLabel);
        locationLayout->addWidget(destCombo);
        mainLayout->addLayout(locationLayout);

        // Date selection
        QHBoxLayout* dateLayout = new QHBoxLayout();
        QLabel* dateLabel = new QLabel("Date of Journey:");
        QDateEdit* dateEdit = new QDateEdit(QDate::currentDate());
        dateEdit->setCalendarPopup(true);

        dateLayout->addWidget(dateLabel);
        dateLayout->addWidget(dateEdit);
        mainLayout->addLayout(dateLayout);

        // Passenger details
        QLabel* nameLabel = new QLabel("Passenger Name:");
        QLineEdit* nameEdit = new QLineEdit();
        QLabel* ageLabel = new QLabel("Age:");
        QLineEdit* ageEdit = new QLineEdit();

        QHBoxLayout* detailsLayout = new QHBoxLayout();
        detailsLayout->addWidget(nameLabel);
        detailsLayout->addWidget(nameEdit);
        detailsLayout->addWidget(ageLabel);
        detailsLayout->addWidget(ageEdit);
        mainLayout->addLayout(detailsLayout);

        // Buttons for actions
        QPushButton* bookButton = new QPushButton("Book Ticket");
        QPushButton* cancelButton = new QPushButton("Cancel Ticket");
        QPushButton* checkButton = new QPushButton("Check Ticket");

        QHBoxLayout* buttonLayout = new QHBoxLayout();
        buttonLayout->addWidget(bookButton);
        buttonLayout->addWidget(cancelButton);
        buttonLayout->addWidget(checkButton);
        mainLayout->addLayout(buttonLayout);

        // Connections
        connect(bookButton, &QPushButton::clicked, this, &FlightReservationGUI::bookTicket);
        connect(cancelButton, &QPushButton::clicked, this, &FlightReservationGUI::cancelTicket);
        connect(checkButton, &QPushButton::clicked, this, &FlightReservationGUI::checkTicket);
    }

private slots:
    void bookTicket() {
        QMessageBox::information(this, "Booking", "Ticket has been booked successfully.");
    }

    void cancelTicket() {
        QMessageBox::information(this, "Cancellation", "Ticket has been canceled successfully.");
    }

    void checkTicket() {
        QMessageBox::information(this, "Ticket Info", "Displaying ticket details.");
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    FlightReservationGUI window;
    window.show();

    return app.exec();
}

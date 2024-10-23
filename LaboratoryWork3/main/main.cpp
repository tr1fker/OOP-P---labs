#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <string>
#include <fstream>
#include <algorithm>

// Класс Service для описания услуги
class Service {
private:
    std::string name;
    double price;
    int duration;  // Длительность услуги в минутах

public:
    Service() : name(""), price(0.0), duration(0) {}

    Service(const std::string& name, double price, int duration)
        : name(name), price(price), duration(duration) {}

    // Геттеры
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getDuration() const { return duration; }

    // Вывод информации об услуге
    void display() const {
        std::cout << "Услуга: " << name << ", Цена: " << price
            << " руб., Длительность: " << duration << " мин." << std::endl;
    }

    // Оператор сравнения для удаления и поиска по имени
    bool operator==(const std::string& serviceName) const {
        return name == serviceName;
    }

    // Запись услуги в файл
    void writeToFile(std::ofstream& file) const {
        file << name << "," << price << "," << duration << std::endl;
    }
};

// Абстрактный базовый класс
class ServiceContainer {
public:
    virtual void addService(const Service& service) = 0;
    virtual void removeService(const std::string& serviceName) = 0;
    virtual void displayServices() const = 0;
    virtual Service* findService(const std::string& serviceName) const = 0;
    virtual void filterServicesByPrice(double maxPrice) const = 0;
    virtual void filterServicesByDuration(int minDuration) const = 0;
    virtual void saveToFile(const std::string& filename) const = 0;
    virtual ~ServiceContainer() {}
};

// Класс, использующий std::vector
class VectorServiceContainer : public ServiceContainer {
private:
    std::vector<Service> services;

public:
    void addService(const Service& service) override {
        services.push_back(service);
    }

    void removeService(const std::string& serviceName) override {
        auto it = std::remove_if(services.begin(), services.end(),
            [&](const Service& s) { return s == serviceName; });
        if (it != services.end()) {
            services.erase(it, services.end());
        }
    }

    void displayServices() const override {
        std::cout << "Услуги (vector):\n";
        for (const auto& service : services) {
            service.display();
        }
    }

    // Поиск услуги по названию
    Service* findService(const std::string& serviceName) const override {
        for (const auto& service : services) {
            if (service == serviceName) {
                return new Service(service);
            }
        }
        return nullptr;
    }

    // Фильтрация услуг по цене
    void filterServicesByPrice(double maxPrice) const override {
        std::cout << "Услуги с ценой меньше " << maxPrice << ":\n";
        for (const auto& service : services) {
            if (service.getPrice() <= maxPrice) {
                service.display();
            }
        }
    }

    // Фильтрация услуг по длительности
    void filterServicesByDuration(int minDuration) const override {
        std::cout << "Услуги с длительностью больше " << minDuration << " минут:\n";
        for (const auto& service : services) {
            if (service.getDuration() >= minDuration) {
                service.display();
            }
        }
    }

    // Запись данных в файл
    void saveToFile(const std::string& filename) const override {
        std::ofstream file(filename);
        if (!file) {
            std::cerr << "Ошибка открытия файла!" << std::endl;
            return;
        }

        for (const auto& service : services) {
            service.writeToFile(file);
        }

        file.close();
        std::cout << "Данные сохранены в файл " << filename << std::endl;
    }
};

// Класс, использующий std::list
class ListServiceContainer : public ServiceContainer {
private:
    std::list<Service> services;

public:
    void addService(const Service& service) override {
        services.push_back(service);
    }

    void removeService(const std::string& serviceName) override {
        services.remove_if([&](const Service& s) { return s == serviceName; });
    }

    void displayServices() const override {
        std::cout << "Услуги (list):\n";
        for (const auto& service : services) {
            service.display();
        }
    }

    // Поиск услуги по названию
    Service* findService(const std::string& serviceName) const override {
        for (const auto& service : services) {
            if (service == serviceName) {
                return new Service(service);
            }
        }
        return nullptr;
    }

    // Фильтрация услуг по цене
    void filterServicesByPrice(double maxPrice) const override {
        std::cout << "Услуги с ценой меньше " << maxPrice << ":\n";
        for (const auto& service : services) {
            if (service.getPrice() <= maxPrice) {
                service.display();
            }
        }
    }

    // Фильтрация услуг по длительности
    void filterServicesByDuration(int minDuration) const override {
        std::cout << "Услуги с длительностью больше " << minDuration << " минут:\n";
        for (const auto& service : services) {
            if (service.getDuration() >= minDuration) {
                service.display();
            }
        }
    }

    // Запись данных в файл
    void saveToFile(const std::string& filename) const override {
        std::ofstream file(filename);
        if (!file) {
            std::cerr << "Ошибка открытия файла!" << std::endl;
            return;
        }

        for (const auto& service : services) {
            service.writeToFile(file);
        }

        file.close();
        std::cout << "Данные сохранены в файл " << filename << std::endl;
    }
};

// Класс, использующий статический массив
class ArrayServiceContainer : public ServiceContainer {
private:
    std::array<Service, 5> services;
    int currentSize = 0;

public:
    void addService(const Service& service) override {
        if (currentSize < services.size()) {
            services[currentSize] = service;
            ++currentSize;
        }
        else {
            std::cout << "Массив заполнен. Невозможно добавить услугу.\n";
        }
    }

    void removeService(const std::string& serviceName) override {
        for (int i = 0; i < currentSize; ++i) {
            if (services[i] == serviceName) {
                for (int j = i; j < currentSize - 1; ++j) {
                    services[j] = services[j + 1];
                }
                --currentSize;
                break;
            }
        }
    }

    void displayServices() const override {
        std::cout << "Услуги (array):\n";
        for (int i = 0; i < currentSize; ++i) {
            services[i].display();
        }
    }

    // Поиск услуги по названию
    Service* findService(const std::string& serviceName) const override {
        for (int i = 0; i < currentSize; ++i) {
            if (services[i] == serviceName) {
                return new Service(services[i]);
            }
        }
        return nullptr;
    }

    // Фильтрация услуг по цене
    void filterServicesByPrice(double maxPrice) const override {
        std::cout << "Услуги с ценой меньше " << maxPrice << ":\n";
        for (int i = 0; i < currentSize; ++i) {
            if (services[i].getPrice() <= maxPrice) {
                services[i].display();
            }
        }
    }

    // Фильтрация услуг по длительности
    void filterServicesByDuration(int minDuration) const override {
        std::cout << "Услуги с длительностью больше " << minDuration << " минут:\n";
        for (int i = 0; i < currentSize; ++i) {
            if (services[i].getDuration() >= minDuration) {
                services[i].display();
            }
        }
    }

    // Запись данных в файл
    void saveToFile(const std::string& filename) const override {
        std::ofstream file(filename);
        if (!file) {
            std::cerr << "Ошибка открытия файла!" << std::endl;
            return;
        }

        for (int i = 0; i < currentSize; ++i) {
            services[i].writeToFile(file);
        }

        file.close();
        std::cout << "Данные сохранены в файл " << filename << std::endl;
    }
};
// Прототип функции меню
void showMenu();

int main() {
    setlocale(LC_ALL, "Rus");
    VectorServiceContainer vectorContainer;
    ListServiceContainer listContainer;
    ArrayServiceContainer arrayContainer;
    int containerChoice;

    std::cout << "Выберите контейнер для работы:\n";
    std::cout << "1. Vector\n";
    std::cout << "2. List\n";
    std::cout << "3. Array\n";
    std::cout << "Введите номер: ";
    std::cin >> containerChoice;

    ServiceContainer* currentContainer = nullptr;

    switch (containerChoice) {
    case 1:
        currentContainer = &vectorContainer;
        break;
    case 2:
        currentContainer = &listContainer;
        break;
    case 3:
        currentContainer = &arrayContainer;
        break;
    default:
        std::cout << "Неверный выбор!" << std::endl;
        return 1;
    }

    int choice;
    std::string name;
    double price;
    int duration;

    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore();  // Игнорируем оставшиеся символы после ввода

        switch (choice) {
        case 1: {  // Добавление услуги
            std::cout << "Введите название услуги: ";
            std::getline(std::cin, name);
            std::cout << "Введите цену: ";
            std::cin >> price;
            std::cout << "Введите длительность (в минутах): ";
            std::cin >> duration;

            Service newService(name, price, duration);
            currentContainer->addService(newService);
            std::cout << "Услуга добавлена!\n";
            break;
        }

        case 2: {  // Удаление услуги
            std::cout << "Введите название услуги для удаления: ";
            std::getline(std::cin, name);
            currentContainer->removeService(name);
            std::cout << "Услуга удалена!\n";
            break;
        }

        case 3: {  // Поиск услуги по названию
            std::cout << "Введите название услуги для поиска: ";
            std::getline(std::cin, name);
            Service* foundService = currentContainer->findService(name);
            if (foundService) {
                foundService->display();
                delete foundService;
            }
            else {
                std::cout << "Услуга не найдена!\n";
            }
            break;
        }

        case 4: {  // Фильтрация по цене
            std::cout << "Введите максимальную цену: ";
            std::cin >> price;
            currentContainer->filterServicesByPrice(price);
            break;
        }

        case 5: {  // Фильтрация по длительности
            std::cout << "Введите минимальную длительность (в минутах): ";
            std::cin >> duration;
            currentContainer->filterServicesByDuration(duration);
            break;
        }

        case 6: {  // Отображение всех услуг
            currentContainer->displayServices();
            break;
        }

        case 7: {  // Сохранение в файл
            std::string filename;
            std::cout << "Введите имя файла для сохранения: ";
            std::cin >> filename;
            currentContainer->saveToFile(filename);
            break;
        }

        case 8:
            std::cout << "Выход из программы.\n";
            break;

        default:
            std::cout << "Неверный выбор! Попробуйте снова.\n";
        }

        std::cout << std::endl;
    } while (choice != 8);

    return 0;
}

// Функция, отображающая меню
void showMenu() {
    std::cout << "\nВыберите действие:\n";
    std::cout << "1. Добавить услугу\n";
    std::cout << "2. Удалить услугу\n";
    std::cout << "3. Найти услугу по названию\n";
    std::cout << "4. Фильтр по цене\n";
    std::cout << "5. Фильтр по длительности\n";
    std::cout << "6. Показать все услуги\n";
    std::cout << "7. Сохранить услуги в файл\n";
    std::cout << "8. Выход\n";
    std::cout << "Введите номер: ";
}


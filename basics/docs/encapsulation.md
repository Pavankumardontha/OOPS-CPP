# Encapsulation in C++ with Example

This example demonstrates the **encapsulation** concept in C++ using a `YoutubeChannel` class.

---

## 🔒 What is Encapsulation?

Encapsulation is the concept of **bundling data (variables)** and **methods (functions)** that operate on that data into a **single unit (class)**. It also involves **restricting direct access** to some of the object's components to enforce **data hiding** and maintain a valid object state.

---

## 💡 Why Encapsulation?

Consider a scenario where we have a `Car` class with a data member `max_speed`.  
If we make `max_speed` public, someone could set it to an invalid value like `-90`, making the object state unrealistic.

✅ To prevent this:
- Make data members **private**
- Use **getter** and **setter** methods to control access
- Apply **validations** in setters to maintain integrity

---

## 📦 Example: YoutubeChannel Class

```cpp
class YoutubeChannel {
private:
    string name;
    string owner_name;
    int subscribers;

public:
    YoutubeChannel(string name, string owner_name) {
        this->name = name;
        this->owner_name = owner_name;
        subscribers = 0;
    }

    string get_name() { return name; }
    string get_owner_name() { return owner_name; }

    void set_subscribers(int new_subscribers) {
        if(new_subscribers >= 0)
            subscribers = new_subscribers;
    }

    void set_name(string new_name) {
        if(new_name != "")
            name = new_name;
    }

    void set_owner_name(string new_owner_name) {
        if(new_owner_name != "")
            owner_name = new_owner_name;
    }

    void subscribe() {
        subscribers++;
    }

    void unsubscribe() {
        if(subscribers > 0)
            subscribers--;
    }

    void info() {
        cout << "name: " << name << " owner: " << owner_name << " subscribers: " << subscribers << endl;
    }
};
```

---

## 🧪 Usage in `main()`

```cpp
int main() {
    YoutubeChannel* yt = new YoutubeChannel("channel", "pavan");
    yt->info();

    yt->set_owner_name("pradeep");
    yt->set_name("channel-1");
    yt->subscribe();

    yt->info();
}
```

---

## ✅ Key Points

- Data members are private to **protect internal state**
- Setters ensure values are **validated** before assignment
- Methods like `subscribe()` and `unsubscribe()` control access safely
- Demonstrates **good object-oriented practices**

---

## 📚 Further Reading

- OOP Concepts: [Encapsulation](https://en.wikipedia.org/wiki/Encapsulation_(computer_programming))
- C++ Classes and Objects
- Design principles for robust software

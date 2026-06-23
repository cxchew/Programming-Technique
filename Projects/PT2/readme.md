# 🏦 Programming Technique II: Equinox Banking System

## 📌 Project Summary
* **Course:** Programming Technique II (SECJ1023 | Sem 2, 2023/2024)
* **Academic Institution:** Universiti Teknologi Malaysia (UTM)
* **Core Technologies:** C++ OOP, Stream Serialization, Account Mutator Patterns, Role-Based Access Control (RBAC).
* **Objective:** To engineer a robust, object-oriented simulated terminal core banking application capable of managing transactional ledgers, user states, and administrator financial audits.

The **Equinox Banking System** is a secure, modular terminal application designed to model real-world banking operations. Moving past basic procedural structures, this engine uses advanced C++ classes, private encapsulation boundaries, inheritance properties, and file-based state persistence. The environment implements a distinct dual-role mechanism allowing standard customers to manage fluid capital actions (deposits, withdrawals, transfers, bill payments) while providing system administrators with absolute auditing visibility over global user registries and continuous transaction logs.

---

## 🛠️ System Capabilities Deployed

### 👤 Customer Terminal Access
* **Capital Velocity Tracking**: Standard routines handling high-accuracy arithmetic deposits, manual withdrawals, and secure cross-account financial transfers.
* **Service Fee Liquidation**: An integrated bill-payment subsystem handling utility processing rules seamlessly.
* **Credit Instrument Modulation**: Flexible runtime switches allowing clients to change credit limit variables and instrument states.

### 👑 Administrator Auditing Hub
* **Unified Account Registry**: Global master loops printing every registered customer file, matching identification details, and displaying account values.
* **Deep Transaction Traversal**: An append-only historical database tracker rendering chronological action descriptions across the system's runtime life.

---

## 🧠 Technical Reflection: Transitioning to True Object-Oriented Paradigm

### 1. What I Learnt: Private Encapsulation & Multi-Object Collaboration
* Developing the *Equinox Banking System* for **Programming Technique II** represented a major evolution in my programming mindset: moving from raw structural steps into clean **Object-Oriented Programming (OOP)** layouts. In our previous assignments, variables sat loosely in open code files. Dealing with banking simulations showed me why strict class data isolation boundaries are absolutely necessary.

* By locking internal variables (like balances and account credentials) behind private boundaries, I learned how to shield objects from accidental out-of-scope adjustments. Every operational change must happen through deliberate, public member functions. 

* Designing interaction points between different entity structures (such as matching a `Customer` item against an `Administrator` loop) taught me how to write highly cohesive, modular, and reusable C++ objects. This directly prepares me for the design patterns and microservice layouts required in corporate data software.

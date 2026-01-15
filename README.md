# urlShortner_C-Llinux

# URL Shortener (C + SQL + Express on Ubuntu)

A simple URL Shortener built from scratch to understand **backend fundamentals, database integration, and system-level programming**.  
This project focuses on learning by reading documentation, writing raw SQL queries, handling DB connections, and implementing routing and redirects without relying on heavy abstractions.

---

## 🚀 Project Overview

This URL Shortener takes a long URL, generates a short code, stores it in a SQL database, and redirects users to the original URL when the short link is accessed.

The goal of this project was **not complexity**, but **clarity and fundamentals**:
- How backend routing works
- How databases are queried directly
- How systems interact in a Linux environment
- How redirects actually function at the HTTP level

---

## 🛠 Tech Stack

- **C** – Core logic and low-level understanding  
- **MySQL** – Persistent storage using raw SQL queries  
- **Express.js (Node.js)** – Routing and API handling  
- **Ubuntu (WSL)** – Development environment  
- **mysql2** – Database driver for Node.js  

---

## ✨ Features

- Generate short codes for long URLs
- Store URLs securely in MySQL
- Redirect short URLs to original long URLs
- Parameterized SQL queries (prevents SQL injection)
- Modular database connection
- Built and tested on Ubuntu (WSL)

---

## 🧠 Architecture / Flow

1. User submits a long URL  
2. A short code is generated  
3. Long URL + short code stored in MySQL  
4. User accesses `/:short_code`  
5. Server queries DB  
6. User is redirected to original URL  

---

## 📂 Project Structure

main_app/
│
├── db.js # Database connection module
├── server.js # Express server
├── handling_routes/
│ └── redirect.js # URL redirect logic
├── sql/
│ └── schema.sql # Database schema
└── README.md


---

## ⚙️ Database Schema

```
--> SQL 
CREATE TABLE urls (
  id INT AUTO_INCREMENT PRIMARY KEY,
  short_code VARCHAR(10) UNIQUE NOT NULL,
  long_url TEXT NOT NULL,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
```


▶️ How to Run
1. Clone the repository
git clone https://github.com/your-username/url-shortener.git
cd url-shortener

2. Install dependencies
npm install

3. Configure database

Update db.js with your MySQL credentials.

4. Start the server
node server.js


Server runs on:

http://localhost:8080

🔗 Example Usage

Short URL:

http://localhost:8080/QzndFB


Redirects to:

https://example.com/some/long/url

📚 What I Learned

How MySQL authentication protocols work

Why connection pooling matters in Express

Writing safe SQL queries using placeholders

Handling redirects properly in backend servers

Debugging real-world backend issues on Linux

Structuring backend projects cleanly

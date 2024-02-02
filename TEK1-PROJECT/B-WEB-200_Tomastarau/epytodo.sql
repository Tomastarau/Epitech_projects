CREATE DATABASE epytodo;

use epytodo;

CREATE TABLE user
(
    id INT AUTO_INCREMENT PRIMARY KEY,
    email VARCHAR(255) NOT NULL UNIQUE,
    name VARCHAR(255) NOT NULL,
    firstname VARCHAR(255) NOT NULL,
    password VARCHAR(255) NOT NULL,
    created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE todo
(
    id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    description TEXT,
    created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    due_time TIMESTAMP,
    user_id INT NOT NULL,
    status ENUM('todo', 'in progress', 'done') NOT NULL DEFAULT 'todo',
    FOREIGN KEY (user_id) REFERENCES user(id)
);

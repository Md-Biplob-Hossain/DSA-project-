
CREATE DATABASE  lms;

CREATE TABLE authors (
    author_id INT PRIMARY KEY AUTO_INCREMENT,
    author_name VARCHAR(100) NOT NULL,
    author_address VARCHAR(200) NOT NULL
);


CREATE TABLE publisher (
    publisher_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL,
    address VARCHAR(200) NOT NULL
);

CREATE TABLE books (
    book_id INT PRIMARY KEY,
    book_title VARCHAR(200) NOT NULL,
    author_id INT ,
    publisher_id INT,
    no_of_copies INT,
    FOREIGN KEY (author_id) REFERENCES authors(author_id),
    FOREIGN KEY (publisher_id) REFERENCES publisher(publisher_id)
);


CREATE TABLE borrowers (
    borrower_id INT PRIMARY KEY AUTO_INCREMENT,
    firstname VARCHAR(100) NOT NULL,
    lastname VARCHAR(100) NOT NULL,
    address VARCHAR(200) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    phone VARCHAR(17) UNIQUE NOT NULL,
    department VARCHAR(100) UNIQUE NOT NULL
);



CREATE TABLE booking (
    booking_id INT PRIMARY KEY AUTO_INCREMENT,
    book_id INT,
    borrower_id INT,
    booking_date DATE NOT NULL,
    available_date DATE NOT NULL,
    FOREIGN KEY (book_id) REFERENCES books(book_id),
    FOREIGN KEY (borrower_id) REFERENCES borrowers(borrower_id)
);


CREATE TABLE borrow_book (
    id INT PRIMARY KEY AUTO_INCREMENT,
    book_id INT,
    borrower_id INT ,
    borrowing_date DATE NOT NULL,
    duedate DATE NOT NULL,
    FOREIGN KEY (book_id) REFERENCES books(book_id),
    FOREIGN KEY (borrower_id) REFERENCES borrowers(borrower_id)
);


CREATE TABLE fine (
    fine_id INT PRIMARY KEY AUTO_INCREMENT,
    borrow_id INT,
    fine_amount DECIMAL(6,2) NOT NULL,
    fine_date DATE NOT NULL,
    FOREIGN KEY (borrow_id) REFERENCES borrowers(borrower_id)
);

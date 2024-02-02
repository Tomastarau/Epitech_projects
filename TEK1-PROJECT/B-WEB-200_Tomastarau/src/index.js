const express = require('express');
const bcrypt = require('bcryptjs');
const app = express();
const port = 3000;

// Middleware setup
app.use(express.urlencoded({ extended: true }));
app.use(express.json());
app.use(express.raw());

// Load environment variables
require('dotenv').config();

// Route setup
require('./routes/user/user')(app, bcrypt);
require('./routes/todos/todos')(app);
require('./routes/auth/auth')(app, bcrypt);

// Start the server
app.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`);
});
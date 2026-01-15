const mysql = require('mysql2')
const connection = mysql.createConnection({
  host: 'localhost',
  user: 'url_user',
  password: 'Strong@1234',
  database: 'url_shortner'
})

connection.connect(err => {
  if (err) {
    console.error("MySQL Connection Failed:", err.message);
  } else {
    console.log("MySQL Connected");
  }
});

module.exports = connection;

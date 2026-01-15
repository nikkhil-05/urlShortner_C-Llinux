const express = require("express");
const app = express();
const db = require("./db.js");

app.get("/:short_code", (req,res)=>{

	 db.query(`select *from urls where short_code="${req.params.short_code}"`, (err, rows) => {
    		if (err) {
      			return res.status(500).json({ error: err.message });
    		}

    		console.log(rows);
	//		res.redirect(rows[0].long_url); 
			let url = rows[0].long_url;
			if (!url.startsWith("http")) {
				url = "https://" + url; 
			}
			res.redirect(url);
		});
});

app.listen(8080, ()=>{
    console.log("server is started!");
});

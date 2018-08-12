const express = require('express');

const morgan = require('morgan');
const cookieParser = require('cookie-parser');

const app = express();

app.use(morgan('dev'));
app.use(cookieParser('QtVideoServerSecretKey'));
app.use(express.json({ limit: '100kb' }));
app.use(express.urlencoded({ extended: false }));

app.use(express.static('public'));

app.use('/', (req, res, next) => {
    console.log('middleware');
    next();
});

app.get('/', (req, res) => res.redirect('/TT.mp4'));

app.listen(3000, () => {
    console.log('Video-server is running at port 3000..');
});
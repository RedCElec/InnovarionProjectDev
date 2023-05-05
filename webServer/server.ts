import express, { Express, Request, Response } from 'express';
import http from 'http';
import fs from 'fs';


//config of the server
const app: Express = express();
const port: number = 3000;
const router = express();
const filePath: string = "./logfile.txt";

//Create and Config an Express Server

const StartServer = () => {
  router.use((req, res, next) => {
      res.on('finish', () => {

      });
      next();
  });

  router.use(express.urlencoded({ extended: true }));
  router.use(express.json());

  /** Rules of API -- Header */
  router.use((req, res, next) => {
      res.header('Access-Control-Allow-Origin', '*');
      res.header('Access-Control-Allow-Headers', 'Origin, X-Requested-With, Content-Type, Accept, Authorization');

      if (req.method == 'OPTIONS') {
          res.header('Access-Control-Allow-Methods', 'PUT, POST, PATCH, DELETE, GET');
          return res.status(200).json({});
      }
      next();
  });


//Main request Type
  router.get('/webhook', (req: Request, res: Response, next) => {
    const timeStamp: number = Date.now();

    //create a new json object
    const newEvent = { timeStamp, req };

    //write data in Log file
    fs.appendFile(filePath, `newEvent : ${newEvent.timeStamp} value : ${newEvent.req.body.value} \n`, (err) => {
      if (err) {
        console.log("error at file writting");
        res.status(401);
      }
      console.log('The new_content was appended successfully');
      res.status(200).json("sdfghjk");
    })
  });



    /** Healthcheck */
    router.get('/ping', (req, res, next) => res.status(200).json({ message: 'hello world' }));

  http.createServer(router).listen(port, () => console.log('server running on port', port));
}


StartServer();

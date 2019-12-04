import { Component } from '@angular/core';
import { HttpClient } from '@angular/common/http';

@Component({
  templateUrl: 'profile.component.html',
  styleUrls: [ './profile.component.scss' ]
})

export class ProfileComponent {
  info: any;
  colCountByScreen: Object;

  constructor(private http: HttpClient) {
    this.info = {};
    this.info.temperatura = 0;
    this.info.tempo = 0;
    var getInfo = () => {
      this.http.get("http://localhost:3000/operation/getInfo", { responseType: 'json' })
       .subscribe((data: any) => {
         this.info = { ...data };
         console.log(data.error.text);
       },
       (error: any) => {
         console.log(JSON.parse(error.error.text));
         this.info = JSON.parse(error.error.text);
       });
    };
    getInfo();
    setInterval(getInfo, 3000);

  }

  cancel() {
    console.log("cancel");
    var cancelOp = () => {
      this.http.post("http://localhost:3000/operation/cancel" , {})
      .subscribe((data: any) => {
        console.log(data);
      });
      this.info.tempo = "cancelado";
    };
    cancelOp();
  }
}

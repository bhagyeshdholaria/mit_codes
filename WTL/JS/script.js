function validate() {
    
    if(document.formname.Firstname.value == "")
    {
        alert("Please enter first name");
        document.formname.Firstname.focus();
    
    }

    if (document.formname.Lastname.value == "") {
        alert("Please enter last name");
        document.formname.Lastname.focus();
    }

    if (document.formname.email.value == "") {
        alert("Please enter email ID");
        document.formname.email.focus();
    }

    if (document.formname.contact.value == "" || ) {
        alert("Please enter contact no.");
        document.formname.contact.focus();
    }
}

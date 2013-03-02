<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form"%>
<%@include file="/WEB-INF/views/root.jsp"%>

<html>
<head>
<title>Insert title here</title>
<meta http-equiv="Content-Type"
	content="text/html; charset=windows-1251">
</head>
<body>

	<br /> &nbsp;&nbsp;
	<span class="badge badge-info"><h1>Chat Booster</h1></span>
	<div class="leftHeader">
		<a href="home.html" class="btn btn-large">Submit New Feed</a>
	</div>
	<br></br>
	<br></br>
	<div class="container">
		<div class="row">
			<div class="span12">
				<form:form method="POST" commandName="emailDomain">
					<form:textarea path="emailText" rows="5"
						placeholder="Write emails to submit us, saperated by ';'"
						style="width: 100%" />
					<div class="control-group error">
						<label class="control-label" for="inputError"> <form:errors
								path="emailText" /></label>
					</div>
					<br />
					<label class="checkbox inline"> <form:checkboxes
							items="${categoryMap}" path="category" />
					</label>
					<div class="control-group error">
						<label class="control-label" for="inputError"> <form:errors
								path="category" /></label>
					</div>
					<br></br>
					<p align="center">
						<button type="submit" value="Submit the feed"
							class="btn btn-success btn-block btn-large" style="width: 60%">Submit
							emails</button>
					</p>
					<p align="center" class="text-info">${var}</p>
				</form:form>
			</div>
		</div>
	</div>




</body>
</html>
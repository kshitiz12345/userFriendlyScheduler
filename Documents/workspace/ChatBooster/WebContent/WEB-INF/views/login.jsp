<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
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
		<a href="email.html" class="btn btn-large">Submit Group Mailing
			Address </a>
	</div>
	<br></br>
	<br></br>
	<div class="container">
		<div class="row">
			<div class="span12">
				<form:form method="POST" commandName="loginDomain">


					<p align="center">
						<form:input path="password"  type="password"/>
						<button type="submit" value="Submit"
							class="btn btn-success btn-block btn-large" style="width: 60%">Submit</button>
					</p>
				</form:form>
			</div>
		</div>
	</div>




</body>
</html>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@include file="/WEB-INF/views/root.jsp"%>
<html>
<head>

<title>Insert title here</title>
<style>
html,body {
	height: 100%;
}

.footer {
	position: absolute;
	color: #666;
	background: #c2c2c2;
	padding: 17px 0 18px 0;
	bottom: 0;
	width: 100%;
	top: 80%;
	color: #666;
}

.leftHeader {
	position: absolute;
	right: 2%;
	top: 4%;
}

footer a {
	color: #999;
}

footer a:hover {
	color: #efefef;
}

/* not required for sticky footer; just pushes hero down a bit */
.wrapper>.container {
	padding-top: 60px;
}
</style>
</head>
<body>
	<br /> &nbsp;&nbsp;
	<span class="badge badge-info"><h1>Chat Booster</h1></span>
	<div class="leftHeader">
		<h1>
			<small>Subtext for header</small>
		</h1>
	</div>
	<br></br>
	<br></br>

	<div class="container">
		<div class="row">
			<div class="span12">
				<div class="hero-unit">
					<h1>Heading</h1>
					<p>Tagline</p>
					<p align="center">
						<a href="forms/home.html" class="btn btn-large btn-success">Submit New Feed</a>
						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
						<a href="forms/email.html" class="btn btn-large">Submit Group Mailing Address </a>
					</p>
				</div>
			</div>
		</div>
	</div>

	<div class="footer">
		<p>
			Put together in less than five minutes by <a
				href="http://www.martinbean.co.uk/" rel="author">Martin Bean</a>.
			Uses <a href="http://twitter.github.com/bootstrap/" rel="external">Twitter
				Bootstrap</a> and <a href="http://ryanfait.com/sticky-footer/"
				rel="external">Ryan Fait&rsquo;s Sticky Footer</a>.
		</p>
	</div>

</body>
</html>
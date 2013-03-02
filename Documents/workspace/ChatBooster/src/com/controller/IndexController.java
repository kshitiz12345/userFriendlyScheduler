package com.controller;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

@Controller
@RequestMapping(value = "/index.html")
public class IndexController extends BaseController {

	@RequestMapping(method = RequestMethod.GET)
	public String showPage(HttpServletRequest request,
			HttpServletResponse response) {

		clearSession(request, response);
		return "index";
	}

}

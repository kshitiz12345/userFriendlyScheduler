package com.validator;

import javax.xml.bind.JAXBException;
import javax.xml.bind.PropertyException;
import javax.xml.bind.ValidationEventHandler;
import javax.xml.bind.Validator;

public class HomeValidator implements Validator{

	@Override
	public ValidationEventHandler getEventHandler() throws JAXBException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object getProperty(String name) throws PropertyException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void setEventHandler(ValidationEventHandler handler)
			throws JAXBException {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setProperty(String name, Object value) throws PropertyException {
		// TODO Auto-generated method stub
		
	}

	@Override
	public boolean validate(Object subrootObj) throws JAXBException {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean validateRoot(Object rootObj) throws JAXBException {
		// TODO Auto-generated method stub
		return false;
	}
	
	


}
